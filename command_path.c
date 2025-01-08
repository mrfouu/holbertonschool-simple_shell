#include "shell.h"

/**
 * find_command_path - Finds the full path of a command.
 * @command: The command to find.
 *
 * Return: The full path of the command, or NULL if not found.
 */
char *find_command_path(char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *command_path = get_path_dir(&path_copy, command);

	free(path_copy);
	return (command_path);
}
