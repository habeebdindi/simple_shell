#include "shell.h"

int main(__attribute__((unused)) int ac, char **av)
{
        char *prompt = "#cisfun$ ", *c, *input = NULL, **argv;
        size_t n = 0;
        pid_t child;
        int status;

        if (isatty(0) == 0)
                printf("%s", prompt);
        while(1)
        {
		print_prompt(prompt);
		getinput(&input, &n);
		argv = parser(input);
		if (!argv)
		{
			free(input);
			continue;
		}
		c = getpath(argv[0]);
		if (!(c))
		{
			free_argv(argv);
			continue;
		}
		child = fork();
		forkcheck_fail(child, input);
		if (child == 0)
		{
			argv[0] = c;
			execute_command(argv, av[0], input);
		}
		else
		{
                        wait(&status);
			free(c);
			free_argv(argv);
		}
        }
        return (0);
}
