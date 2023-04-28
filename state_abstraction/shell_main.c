#include "shell.h"
/**
 * main - main function for the shell.
 * @ac: argument count.
 * @av: ana array of pointers to the program.
 * Return: always 0 (succes).
 */
int main(__attribute__((unused)) int ac, char **av)
{
	signal(SIGINT, SIG_IGN);
	while (1)
	{
		mode_run(av[0]);
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
