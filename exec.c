#include "shell.h"

/**
 * execute - Executes a command with arguments
 * @args: An array of arguments
 */
void execute(char **args)
{
	char *path = NULL;

	if (args[0][0] == '/' || args[0][0] == '.')
	{
		path = strdup(args[0]);  /* Command is an absolute or relative path */
	}
	else
	{
		path = find_command(args[0]);  /* Search in PATH */
	}

	if (path)
	{
		if (fork() == 0)
		{
			execve(path, args, environ);
			perror("Error");
			exit(EXIT_FAILURE);
		}
		wait(NULL);
		free(path);
	}
	else
	{
		perror("Command not found");
	}
}

