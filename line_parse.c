#include "shell.h"

#define MAX_TOKENS 256  /* Définir un nombre maximal de tokens */
#define TOKEN_DELIMITERS " \t\r\n\a"

/**
 * tokenize - Splits a line into tokens
 * @line: The line to be tokenized
 *
 * Return: An array of tokens
 */
char **tokenize(char *line)
{
	char **tokens;
	char *token;
	int position = 0;

	tokens = malloc(MAX_TOKENS * sizeof(char *));
	if (!tokens)
	{
		fprintf(stderr, "allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOKEN_DELIMITERS);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= MAX_TOKENS)
		{
			fprintf(stderr, "Too many tokens\n");
			free(tokens);
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, TOKEN_DELIMITERS);
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 * free_tokens - frees the memory allocated
 * @tokens: the array of tokens to be freed
 */
void free_tokens(char **tokens)
{
	free(tokens);
}
