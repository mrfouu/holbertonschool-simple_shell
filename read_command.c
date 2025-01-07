#include "shell.h"

/**
 * read_command - Reads the user input
 * @buffer: The buffer to store the command
 */
void read_command(char *buffer)
{
	if (fgets(buffer, 1024, stdin) == NULL)
	{
		if (feof(stdin))
			exit(0); /* End of file (Ctrl+D) */
		else
			perror("fgets");
	}
	buffer[strcspn(buffer, "\n")] = '\0'; /* Remove newline character */
}
