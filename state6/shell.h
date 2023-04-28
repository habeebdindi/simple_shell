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

/* The prototypes declared here are not in any order */


/* helpers, custom implementation of disallowed funcs */
char *_memset(char *s, char b, unsigned int n);
char *itoa(int i, char b[]);

/* printing and parsing */
void print_prompt(char *prompt);
char *getinput(void);
char **parser(char *input);

/* command execution */
void forkcheck_fail(pid_t child, char *input);
void execute_command(char **argv, char *av0, char *input, int *status,
		     char *c);

/* shell runner, selects interactive or non-interactive */
void mode_run(char *av0, int *i);

/* handles the path */
char *getpath(char *command);
void err_clean(int *i, char *av0, char *input, char **argv, int *status);

/* string manipulation */
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);

/* builtins */
int num_builtins(void);
int handle_builtin(int *i, char **argv, char *input, char *av0, int *status);

/* builtin funcs declarations */
int _cdd(char **args, char *input);
int _exitt(char **argv, char *input);
int _envv(char **argv, char *input);

/* builtin errors */
void cd_err(int *i, char *av0, char *input, char **argv, int *status);
void env_err(char *input, char **argv, int *status);

#endif /* MAIN_H */
