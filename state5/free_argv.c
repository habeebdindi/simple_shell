#include "shell.h"
/**
 * free_argv - frees argv.
 * @argv: array of pointers to parsed input.
 * Return: void
 */
void free_argv(char **argv)
{
	int i;

	for (i = 0; argv[i] != NULL; i++)
		free(argv[i]);
	free(argv);
}

/**
 * err_clean - prints error message and cleans up if a command doesn't exist.
 * @i: pointer to the current shell iteration.
 * @av0: the name of the shell program.
 * @argv: parsed user input.
 * @input: user input to shell.
 * Return: void.
 */
void err_clean(int *i, char *av0, char *input, char **argv)
{
	char err_msg[200];

	_memset(err_msg, 0, sizeof(err_msg));
	sprintf(err_msg, "%s: %d: %s: not found", av0, *i, argv[0]);
	write(STDERR_FILENO, err_msg, strlen(err_msg));
	write(STDERR_FILENO, "\n", _strlen("\n"));
	free(argv);
	free(input);
}
