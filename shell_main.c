#include "shell.h"
/**
 * main - main function for the shell.
 * @ac: argument count.
 * @av: ana array of pointers to the program.
 * Return: always 0 (succes).
 */
int main(__attribute__((unused)) int ac, char **av)
{
        char *prompt = "#cisfun$ ", *c, *input = NULL, **argv;
        size_t n = 0;

        if (isatty(0) == 0)
                printf("%s", prompt);
        while(1)
        {
		print_prompt(prompt);
		getinput(&input, &n);
		argv = parser(input);
		if (!argv)
			continue;
		c = getpath(argv[0]);
		if (!c)
		{
			free_argv(argv);
			continue;
		}
		execute_command(argv, av[0], input, c);
        }
        return (0);
}
