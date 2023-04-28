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
			{
				free(line);
				write(STDERR_FILENO, "\n", strlen("\n"));
				exit(EXIT_SUCCESS);
			}
			else
			{
				free(line);
				return (NULL);
			}
		}
		else
		{
			perror("getline");
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
