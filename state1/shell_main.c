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
		print_prompt(prompt);
		input = getinput();
		argv = parser(input);
		/* _exitt(argv, input); */
		/* c = getpath(argv[0]); */
		/* if (!c) */
		/* { */
		/* 	err_clean(&i, av[0], argv); */
		/* 	continue; */
		/* } */
		execute_command(argv, av[0], input/* , c */);
	}
	return (0);
}
