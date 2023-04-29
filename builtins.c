#include "shell.h"

/**
 * num_builtins - returns the number of builtin commands.
 * Return: no. of builtins as stated above.
 */
int num_builtins(void)
{
	char *builtin_arr[] = {"cd", "env", "exit"};

	return (sizeof(builtin_arr) / sizeof(char *));
}

/**
 * handle_builtin - handles builtin commands.
 * @i: pointer to the current shell iteration.
 * @argv: parsed user input.
 * @input: user input to shell.
 * @av0: the name of the shell program.
 * @status: execution status.
 * Return: 0 on success and 1 on failure.
 */
int handle_builtin(int *i, char **argv, char *input, char *av0, int *status)
{
	int (*builtin_func[]) (char **, char *, int *status) = {_cdd, _envv, _exitt};
	char *builtin_arr[] = {"cd", "env", "exit"};
	int j, ret;

	for (j = 0; j < num_builtins(); j++)
	{
		if (strcmp(argv[0], builtin_arr[j]) == 0)
		{
			ret = ((*builtin_func[j])(argv, input, status));
			switch (ret)
			{
				case 0:
					return (0);
				case 1:
					env_err(input, argv, status);
					return (0);
				case -1:
					cd_err(i, av0, input, argv, status);
					return (0);
				case 2:
					exit_err(i, av0, input, argv, status);
			}
		}
	}
	return (1);
}

/**
 * _envv - prints the environment variables.
 * @argv: an array of pointers to the env variables.
 * @input: user input to shell.
 * @status: exit status of last process.
 * Return: 0 on success, 1 on failure.
 */
int _envv(char **argv, char *input, __attribute__((unused))int *status)
{
	char **env = environ;

	if (argv[1])
		return (1);
	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", _strlen("\n"));
		env++;
	}
	free(argv);
	free(input);
	return (0);
}

/**
 * _exitt - exits the shell.
 * @argv: pointer to a pointer to an array of parsed input.
 * @input: buffer to the command.
 * @status: exit status of last process.
 * Return: doesn't return.
 */
int _exitt(char **argv, char *input, int *status)
{
	if (argv[1])
	{
		if (_atoi(argv[1]) > 0 ||
		    (_atoi(argv[1]) == 0 && _strcmp(argv[1], "0") == 0))
			*status = _atoi(argv[1]);
		else
		{
			*status = 2;
			return (2);
		}
	}
	free(argv);
	free(input);
	exit(*status);
}
/**
 * _cdd - changes directory.
 * @args: pointer to a pointer to an array of parsed input.
 * @input: buffer to the command.
 * @status: exit status of last process.
 * Return: -1 on failure and 0 on success.
 */
int _cdd(char **args, char *input, __attribute__((unused))int *status)
{
	char *home, buf[1024];

	if (args[1] == NULL)
	{
		home = getenv("HOME");
		if (!home || chdir(home) != 0)
			return (-1);
	}
	else
		if (chdir(args[1]) != 0)
			return (-1);

	if (getcwd(buf, sizeof(buf)) != NULL)
		if(!isatty(0))
			write(STDIN_FILENO, buf, _strlen(buf));
	free(args);
	free(input);
	return (0);
}
