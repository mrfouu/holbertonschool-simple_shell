#include "shell.h"

/**
 * execute_command - Executes the command entered by the user.
 * @command: The command to be executed.
 */
void execute_command(char *command)
{
	char *argv[2];
	pid_t pid;
	int status;
	char *command_path;

	/* Find the command path */
	command_path = find_command_path(command);
	if (command_path == NULL)
	{
		fprintf(stderr, "%s: command not found\n", command);
		return;
	}

	/* Prepare the arguments for execve */
	argv[0] = command_path;
	argv[1] = NULL;

	/* Create a new process to execute the command */
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(command_path);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* In the child process: execute the command */
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("execve");
			free(command_path);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* In the parent process: wait for the child to finish */
		wait(&status);
	}

	free(command_path);
}
