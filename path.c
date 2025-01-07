#include "shell.h"

/**
 * find_command - Searches for a command in the PATH
 * @command: Command to find
 * Return: Full path of the command or NULL if not found
 */
char *find_command(char *command)
{
	char *path, *path_copy, *token, *full_path;
	size_t len;
	struct stat st;

	if (stat(command, &st) == 0 && (st.st_mode & S_IXUSR))
		return (strdup(command));

	path = getenv("PATH");
	if (!path)
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		len = strlen(token) + strlen(command) + 2;
		full_path = malloc(len);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}
		snprintf(full_path, len, "%s/%s", token, command);
		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
