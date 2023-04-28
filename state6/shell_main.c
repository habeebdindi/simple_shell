#include "shell.h"
/**
 * main - main function for the shell.
 * @ac: argument count.
 * @av: ana array of pointers to the program.
 * Return: always 0 (succes).
 */
int main(__attribute__((unused)) int ac, char **av)
{
	int loop_track = 0;

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		mode_run(av[0], &loop_track);
		loop_track++;
	}
	return (0);
}
