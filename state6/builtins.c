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
 * @argv: parsed input.
 * Return: 0 on success and 1 on failure.
 */
int handle_builtin(int *i, char **argv, char *input, char *av0, int *status)
{
	int (*builtin_func[]) (char **, char *) = {_cdd, _envv, _exitt};
	char *builtin_arr[] = {"cd", "env", "exit"};
	int j, ret;

	for (j = 0; j < num_builtins(); j++)
	{
		if (strcmp(argv[0], builtin_arr[j]) == 0)
		{
			ret = ((*builtin_func[j])(argv, input));
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
			}
		}
	}
	return (1);
}

/**
 * print_env - prints the environment variables.
 * @env: an array of pointers to the env variables.
 * Return: 0 on success, 1 on failure.
 */
int _envv(char **argv, char *input)
{
	char **env = environ;

	if (argv[1])
		return (1);
	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		env++;
	}
	write(STDOUT_FILENO, "\n", _strlen("\n"));
        free(argv);
	free(input);
	return (0);
}

/**
 * _exitt - exits the shell.
 * @argv: pointer to a pointer to an array of parsed input.
 * @input: buffer to the command.
 * Return: doesn't return.
 */
int _exitt(char **argv, char *input)
{
	free(argv);
	free(input);
	exit(0);
}
/**
 * _cdd - changes directory.
 * @argv: pointer to a pointer to an array of parsed input.
 * @input: buffer to the command.
 * Return: -1 on failure and 0 on success.
 */
int _cdd(char **args, char *input)
{
	char *home;

	if (args[1] == NULL)
	{
		home = getenv("HOME");
		if (!home || chdir(home) != 0)
		{
			return (-1);
		}

	}
	else
		if (chdir(args[1]) != 0)
		{
			return (-1);
		}
	free(args);
	free(input);
	return (0);
}
