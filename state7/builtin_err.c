#include "shell.h"

/**
 * cd_err - prints error message and cleans up if a command doesn't exist.
 * @i: pointer to the current shell iteration.
 * @av0: the name of the shell program.
 * @argv: parsed user input.
 * @input: user input to shell.
 * @status: execution status.
 * Return: void.
 */
void cd_err(int *i, char *av0, char *input, char **argv, int *status)
{
	char err_msg[200];

	_memset(err_msg, 0, sizeof(err_msg));
	sprintf(err_msg, "%s: %d: %s: can't cd to %s", av0, *i, argv[0], argv[1]);
	write(STDERR_FILENO, err_msg, strlen(err_msg));
	write(STDERR_FILENO, "\n", _strlen("\n"));
	free(argv);
	free(input);
	*status = 2;
	if (!isatty(0))
		exit(*status);
}

/**
 * env_err - prints error message and cleans up if a command doesn't exist.
 * @argv: parsed user input.
 * @input: user input to shell.
 * @status: execution status.
 * Return: void.
 */
void env_err(char *input, char **argv, int *status)
{
	char err_msg[200];

	_memset(err_msg, 0, sizeof(err_msg));
	sprintf(err_msg, "%s: '%s': No such file or directory", argv[0], argv[1]);
	write(STDERR_FILENO, err_msg, strlen(err_msg));
	write(STDERR_FILENO, "\n", _strlen("\n"));
	free(argv);
	free(input);
	*status = 127;
	if (!isatty(0))
		exit(*status);
}
