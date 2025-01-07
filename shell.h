#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Function prototypes */
void prompt(void);
char **tokenize(char *line);
void execute(char **args);
void free_tokens(char **tokens);
char *find_command(char *command);
void print_env(void);

#endif /* SHELL_H */
