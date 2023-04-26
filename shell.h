#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

void _exitt(char *command);

char *_memset(char *s, char b, unsigned int n);

void print_prompt(char *prompt);
void getinput(char **input, size_t *n);

char **parser(char *input);
void forkcheck_fail(pid_t child, char *input);
void execute_command(char **argv, char *av0, char *input, char *c);
void free_argv(char **argv);

void print_env(char **env);

char *getpath(char *command);

char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
#endif /* MAIN_H */
