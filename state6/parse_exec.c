#include "shell.h"
/**
 * parser - splits the input string
 * @input: pointer to a string
 * Return: pointer to a pointer to an array of strings
 */
char **parser(char *input)
{
	int tok_size = TOK_BUFSIZE, index = 0;
	char *token, **argv = malloc(tok_size * sizeof(char *));

	if (!argv)
	{
		free(input);
		exit(EXIT_FAILURE);
	}

	token = strtok(input, TOK_DELIM);
	while (token != NULL)
	{
		argv[index] = token;
		index++;
		token = strtok(NULL, TOK_DELIM);
	}
	argv[index] = NULL;
	if (!argv[0])
	{
		free(argv);
		free(input);
		return (NULL);
	}
	return (argv);
}

/**
 * execute_command - executes commands.
 * @argv: array of pointers to parsed input.
 * @av0: name of the shell program.
 * @input: buffer containing input.
 * @c: pointer to the full path of command.
 * @status: exit status of child proc will be stored here.
 * Return: void.
 */
void execute_command(char **argv, char *av0, char *input, int *status, char *c)
{
	pid_t child;

	child = fork();

	forkcheck_fail(child, input);
	if (child == 0)
	{
		argv[0] = c;
		execve(argv[0], argv, environ);
		perror(av0);
		free(argv);
		free(input);
		free(c);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(status);
		if (WIFEXITED(*status))
			*status = WEXITSTATUS(*status);
		free(argv);
		free(input);
		free(c);
	}
}
