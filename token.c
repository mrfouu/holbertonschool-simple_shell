#include "shell.h"

/**
 * tokenize - Splits a command into arguments
 * @command: The command to split
 *
 * Return: An array of arguments
 */
char **tokenize(char *command)
{
	char **tokens = NULL;
	char *token = NULL;
	size_t i = 0, bufsize = 64;

	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
		return (NULL);

	token = strtok(command, " ");
	while (token)
	{
		tokens[i++] = strdup(token);
		if (i >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
				return (NULL);
		}
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;
	return (tokens);
}

