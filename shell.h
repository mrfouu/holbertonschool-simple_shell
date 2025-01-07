#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;

/* Function Prototypes */
void execute(char **args);  /* Ensure this prototype is present */
void execute_command(char *command);
char **tokenize(char *command);
char *find_command(char *command);
void print_env(void);
void handle_exit(char *command);

#endif /* SHELL_H */

