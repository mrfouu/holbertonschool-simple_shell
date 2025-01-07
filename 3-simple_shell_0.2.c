"simple_shell.h"
#include <string.h>

/**
 
@brief Executes the given command.
This function forks a child process to execute the given command
using execve. If the command execution fails, an error message
is printed.
@param input The command to be executed.*/
void execute_command(char input)
{
    charargs[MAX_LINE / 2 + 1]; /* Command line arguments /
    pid_t pid = fork(); / Fork a child process /

    if (pid < 0)
    {
        perror("fork"); / Error handling for fork /
    }
    else if (pid == 0)
    {
        / Child process /
        int i = 0;
        args[i] = strtok(input, " "); / Tokenize input /
        while (args[i] != NULL)
        {
            i++;
            args[i] = strtok(NULL, " "); / Continue tokenizing /
        }

        / Execute the command /
        if (execve(args[0], args, NULL) == -1)
        {
            perror("execve"); / Error handling for execve /
        }
        _exit(EXIT_FAILURE); / Exit child process /
    }
    else
    {
        / Parent process waits for child to complete */
        waitpid(pid, NULL, 0);
    }
}
