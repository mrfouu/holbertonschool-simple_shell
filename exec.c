#include "shell.h"

/**
 * execute - Executes a command
 * @args: Array of arguments
 */
void execute(char **args)
{
	pid_t pid;
	int status;
	char *command_path;

	if (!args || !args[0])
		return;

	if (strcmp(args[0], "env") == 0)
	{
		print_env();
		return;
	}

	command_path = find_command(args[0]);
	if (!command_path)
	{
		perror("Command not found");
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(command_path, args, NULL) == -1)
		{
			perror("Error");
			free(command_path);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Error");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	free(command_path);
}
