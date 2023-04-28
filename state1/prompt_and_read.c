#include "shell.h"

/**
 * print_prompt - prints prompt to the user
 * @prompt: array containing prompt to be printed
 * Return: void
 */
void print_prompt(char *prompt)
{
	if (isatty(0))
	{
		write(STDOUT_FILENO, prompt, strlen(prompt));
		fflush(stdout);
	}
}
/**
 * getinput - gets input from the user
 * @n: size of the buffer storing the input
 * @input: buffer where input is stored
 * Return: void
 */
char *getinput(void)
{
	char *line = NULL;
	size_t n = 0;
	if (getline(&line, &n, stdin) == -1)
	{
		if (feof(stdin))
		{
			if (isatty(0))
				write(STDERR_FILENO, "\n", strlen("\n"));
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	printf("line: %s\n", line);
	return (line);
}

/* void print_prompt2(void) */
/* { */
/* 	write(STDERR_FILENO, "> ", _strlen("> ")); */
/* } */
