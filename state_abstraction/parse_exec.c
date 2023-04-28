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
	return (argv);
}

/**
 * execute_command - executes commands.
 * @argv: array of pointers to parsed input.
 * @av0: name of the shell program.
 * @input: buffer containing input.
 * @c: pointer to the full path of command.
 * Return: void.
 */
void execute_command(char **argv, char *av0, char *input, int *status/* , char *c */)
{
	pid_t child;

	if (!argv[0])
	{
		free(argv);
		free(input);
		return;
        }
	child = fork();

	forkcheck_fail(child, input);
	if (child == 0)
	{
		/* argv[0] = c; */
		execve(argv[0], argv, environ);
		perror(av0);
		free(argv);
		free(input);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(status);
		if (WIFEXITED(*status))
		    *status = WEXITSTATUS(*status);
		if (!isatty(0))
		{
			free(argv);
			free(input);
			return;
		}
        	free(argv);
		free(input);
		/* free(c); */
	}
}

/**
 * print_env - prints the enviromanet variables.
 * @env: an array of pointers to the env variables.
 * Return: void.
 */
void print_env(char **env)
{
	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		env++;
	}
	write(STDOUT_FILENO, "\n", _strlen("\n"));
}

/**
 * _envv - checks if the user has entered the env command builtin.
 * @argv: array of pointers to parsed input.
 * Return: 0 if env is not detected, 1 if detected.
 */
int _envv(char **argv)
{
	if (_strcmp(argv[0], "env") == 0 && argv[1] == NULL)
	{
		print_env(environ);
		free_argv(argv);
		return (1);
	}
	return (0);
}
