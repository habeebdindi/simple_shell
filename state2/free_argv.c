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

void err_clean(int *i, char *av0, char **argv)
{
	char i_buf[100], err_msg[200];

	_memset(i_buf, 0, sizeof(i_buf));
	_memset(err_msg, 0, sizeof(err_msg));
	_strcpy(err_msg, av0);
	_strcat(err_msg, ": ");
	_strcat(err_msg, itoa(*i, i_buf));
	_strcat(err_msg, ": ");
	_strcat(err_msg, argv[0]);
	_strcat(err_msg, ": ");
	_strcat(err_msg, "not found");
	write(STDERR_FILENO, err_msg, strlen(err_msg));
	write(STDERR_FILENO, "\n", _strlen("\n"));
	free_argv(argv);
}
