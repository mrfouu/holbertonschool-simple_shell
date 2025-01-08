#include "shell.h"

/**
 * prompt - Displays the shell prompt and reads user input.
 */
void prompt(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	/* Display the shell prompt */
	printf("$ ");
	/* Read the user input */
	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		/* Handle end-of-file condition (Ctrl+D) */
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	/* Remove the newline character from the input */
	line[nread - 1] = '\0';
	/* Execute the command entered by the user */
	execute_command(line);
	free(line);
}
