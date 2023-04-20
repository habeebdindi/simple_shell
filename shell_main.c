#include "shell.h"

int main(__attribute__((unused)) int ac, char **av)
{
        char *prompt = "#cisfun$ ", *input = NULL;
        size_t n = 0;
        pid_t child;
        int status;

        if (isatty(0) == 0)
                printf("%s", prompt);
        while(1)
        {
                print_prompt(prompt);

                getinput(&input, &n);

                child = fork();

                forkcheck_fail(child, input);

                if (child == 0)
                        fork_pass(input, av[0]);

                else
                        wait(&status);
        }
        return (0);
}
