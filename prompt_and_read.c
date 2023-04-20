#include "shell.h"

void print_prompt(char *prompt)
{
        if (isatty(0) == 1)
        {
                printf("%s", prompt);
                fflush(stdout);
        }
}

void getinput(char **input, size_t *n)
{
        if (getline(input, n, stdin) == -1)
        {
                free(*input);
                exit(EXIT_FAILURE);
        }
}
