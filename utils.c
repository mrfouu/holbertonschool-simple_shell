#include "main.h"

void prompt()
{
    write(STDOUT_FILENO, "MyShell$ ", 9);
}

char **tokenize_input(char *input)
{
    char **tokens = malloc(sizeof(char *) * 1024);
    char *token;
    int i = 0;

    if (!tokens)
    {
        perror("malloc failed");
        exit(1);
    }

    token = strtok(input, " \n");
    while (token)
    {
        tokens[i] = token;
        token = strtok(NULL, " \n");
        i++;
    }
    tokens[i] = NULL;

    return tokens;
}

void execute_command(char **args)
{
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Failed to create child process");
        exit(1);
    }

    if (child_pid == 0)
    {
        if (execve(args[0], args, NULL) == -1)
        {
            perror("Failed to execute command");
            exit(1);
        }
    }
    else
    {
        wait(&status);
    }
}
