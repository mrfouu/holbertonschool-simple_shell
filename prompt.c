#include "shell.h"

/**
 * prompt - Displays the prompt for the shell
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}
