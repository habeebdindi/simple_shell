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
