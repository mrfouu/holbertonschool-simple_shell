#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#ifndef PATH_MAX
#define PATH_MAX 4096  /* Définir PATH_MAX si elle n'est pas définie */
#endif
char *read_line(void);
char **parse_line(char *line);
void execute(char **args);
void prompt(void);
void print_env(void);
char *find_path(char *command);
extern char **environ;
int handle_builtin(char **args);
char **tokenize(char *line);

#endif
