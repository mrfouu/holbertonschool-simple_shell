#include "shell.h"

/**
 * get_path_dir - Gets the directory from the PATH variable.
 * @path_copy: Pointer to the copy of the PATH variable.
 * @command: The command to find.
 *
 * Return: The full path of the command, or NULL if not found.
 */
char *get_path_dir(char **path_copy, char *command)
{
	char *dir = strtok(*path_copy, ":");
	char *command_path = malloc(strlen(dir) + strlen(command) + 2);

	/* Check if the command is an absolute or relative path */
	if (command[0] == '/' || command[0] == '.')
	{
		if (access(command, X_OK) == 0)
		{
			return (strdup(command));
		}
		return (NULL);
	}

	while (dir != NULL)
	{
		sprintf(command_path, "%s/%s", dir, command);
		if (access(command_path, X_OK) == 0)
		{
			return (command_path);
		}
		dir = strtok(NULL, ":");
	}

	free(command_path);
	return (NULL);
}
