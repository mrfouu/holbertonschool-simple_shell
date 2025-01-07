#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Déclarations des fonctions */
void prompt();
char **tokenize_input(char *input);
void execute_command(char **args);

#endif /* MAIN_H */

