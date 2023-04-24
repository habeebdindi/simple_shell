#include "shell.h"

int main(__attribute__((unused)) int ac, char **av)
{
        char *prompt = "#cisfun$ ", *input = NULL, **argv;
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
			exit(EXIT_FAILURE);
		}
                child = fork();
		forkcheck_fail(child, input);
		if (child == 0)
			execute_command(argv, av[0], input);
		else
		{
                        wait(&status);
			free_argv(argv);
		}
        }
        return (0);
}
