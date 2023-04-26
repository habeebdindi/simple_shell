#include "shell.h"
/**
 * parser - splits the input string
 * @input: pointer to a string
 * Return: pointer to a pointer to an array of strings
 */
char **parser(char *input)
{
	char *in_copy, *token, **argv;
	int i, j;
	
	input[_strlen(input) - 1] = '\0';
	in_copy = _strdup(input);
	if (!in_copy)
		return (NULL);

	token = strtok(in_copy, " ");
	for (i = 1; token != NULL; i++)
		token = strtok(NULL, " ");
	free(in_copy);

	argv = malloc(sizeof(char *) * (i + 1));
	if (!argv)
		return (NULL);
	token = strtok(input, " ");
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(strlen(token) + 1);
		if (!argv[i])
		{
			for (j = i - 1; j >= 0; j--)
				free(argv[j]);
			free(argv);
			return (NULL);
		}
		_strcpy(argv[i], token);
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;
	if (!argv[0])
	{
		free_argv(argv);
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
 * Return: void.
 */
void execute_command(char **argv, char *av0, char *input, char *c)
{
	int status;
	pid_t child;

	child = fork();

	forkcheck_fail(child, input);
	if (child == 0)
	{
		argv[0] = c;
		execve(argv[0], argv, environ);
		perror(av0);
		free_argv(argv);
		free(input);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
		free(c);
		free_argv(argv);
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
		write(STDOUT_FILENO, *env, strlen(*env));
		env++;
	}
	write(STDOUT_FILENO, "\n", strlen("\n"));
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
