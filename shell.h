#ifndef SHELL_H
#define SHELL_H
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

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

char *_memset(char *s, char b, unsigned int n);

void _exitt(char **argv, char *input);

void print_prompt(char *prompt);
char *getinput(void);
void forkcheck_fail(pid_t child, char *input);
char **parser(char *input);
void free_argv(char **argv);
void execute_command(char **argv, char *av0, char *input, int *status,
		     char *c);

void err_clean(int *i, char *av0, char *input, char **argv);

void mode_run(char *av0, int *i);

void print_env(char **env);
int _envv(char **argv);

char *getpath(char *command);

char *itoa(int i, char b[]);

char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
#endif /* MAIN_H */
