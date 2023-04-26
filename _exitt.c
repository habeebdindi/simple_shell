#include "shell.h"
/**
 * _exitt - exits the shell.
 * @argv: pointer to a pointer to an array of parsed input.
 * @input: buffer to the command.
 * Return: void.
 */

void _exitt(char **argv, char *input)
{
	char *ptr = argv[0];

	if (_strcmp(ptr, "exit") == 0 && argv[1] == NULL)
	{
		free_argv(argv);
		free(input);
		exit(0);
	}
}

