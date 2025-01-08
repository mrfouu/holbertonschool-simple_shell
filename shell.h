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
void execute_command(char *command);
char *find_command_path(char *command);
char *get_path_dir(char **path_copy, char *command);

#endif /* SHELL_H */
