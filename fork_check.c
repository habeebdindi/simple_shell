#include "shell.h"

/**
 * forkcheck_fail - checks if the call to fork failed.
 * @child: process id returned by fork.
 * @input: pointer to a buffer where user input is.
 *
 * Return: void.
 */
void forkcheck_fail(pid_t child, char *input)
{
	if (child == -1)
	{
		free(input);
		perror("Error");
		exit(EXIT_FAILURE);
	}
}
