#include "main.h"

int main(int argc, char **argv)
{
    char *buf = NULL;
    size_t count = 0;
    ssize_t nread;
    char **args;

    (void)argc;
    (void)argv;

    while (1)
    {
        prompt();

        nread = getline(&buf, &count, stdin);
        if (nread == -1)
        {
            perror("Exiting shell");
            free(buf);
            exit(1);
        }

        args = tokenize_input(buf);
        if (args[0] != NULL)
        {
            execute_command(args);
        }

        free(args);
    }

    free(buf);
    return 0;
}
