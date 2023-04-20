#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>

void print_prompt(char *prompt);
void getinput(char **input, size_t *n);
void forkcheck_fail(pid_t child, char *input);
void fork_pass(char *input, char *av0);

char *_strcpy(char *dest, char *src);
int _strlen(char *s);

#endif /* MAIN_H */
