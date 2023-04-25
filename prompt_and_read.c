#include "shell.h"
/**
 * print_prompt - prints prompt to the user
 * @prompt: array containing prompt to be printed
 * Return: void
 */
void print_prompt(char *prompt)
{
	if (isatty(0) == 1)
	{
		printf("%s", prompt);
		fflush(stdout);
	}
}

/**
 * getinput - gets input from the user
 * @n: size of the buffer storing the input
 * @input: buffer where input is stored
 * Return: void
 */
void getinput(char **input, size_t *n)
{
	if (getline(input, n, stdin) == -1)
	{
		free(*input);
		exit(EXIT_FAILURE);
	}
}
