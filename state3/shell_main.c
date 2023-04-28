#include "shell.h"
/**
 * main - main function for the shell.
 * @ac: argument count.
 * @av: ana array of pointers to the program.
 * Return: always 0 (succes).
 */
int main(__attribute__((unused)) int ac, char **av)
{
	char *prompt = "#cisfun$ ", /* *c,  */*input, **argv;

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		if (!isatty(0))
		{
			while ((input = getinput()) != NULL )
			{
				argv = parser(input);
				execute_command(argv, av[0], input/* , c */);
			}
			free(input);
			exit(EXIT_SUCCESS);
		}
		else
		{
			print_prompt(prompt);
			input = getinput();
			argv = parser(input);
			execute_command(argv, av[0], input/* , c */);
		}
		/* _exitt(argv, input); */
		/* c = getpath(argv[0]); */
		/* if (!c) */
		/* { */
		/* 	err_clean(&i, av[0], argv); */
		/* 	continue; */
		/* } */
	}
	return (0);
}
