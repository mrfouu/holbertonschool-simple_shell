#include "shell.h"

/**
 * tokenize - Splits a line into an array of tokens
 * @line: The line to split
 * Return: Array of tokens
 */
char **tokenize(char *line)
{
	char **tokens = NULL;
	char *token;
	size_t i = 0, bufsize = 64;

	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
		return (NULL);

	token = strtok(line, " \t\r\n");
	while (token != NULL)
	{
		tokens[i] = strdup(token);
		if (!tokens[i])
		{
			free_tokens(tokens);
			return (NULL);
		}
		i++;
		if (i >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
				return (NULL);
		}
		token = strtok(NULL, " \t\r\n");
	}
	tokens[i] = NULL;
	return (tokens);
}
