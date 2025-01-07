#include "shell.h"

/**
 * print_env - Prints the environment variables
 */
void print_env(void)
{
	extern char **environ;
	size_t i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * free_tokens - Frees an array of tokens
 * @tokens: The array of tokens
 */
void free_tokens(char **tokens)
{
	size_t i;

	if (!tokens)
		return;

	for (i = 0; tokens[i]; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}
