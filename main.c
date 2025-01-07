#include "shell.h"

/**
 * main - Entry point for the simple shell
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	char **args;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		prompt();
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			free(line);
			break;
		}

		args = tokenize(line);
		if (args)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				free_tokens(args);
				free(line);
				break;
			}
			execute(args);
			free_tokens(args);
		}
	}

	return (0);
}
