#include "shell.h"

void forkcheck_fail(pid_t child, char *input)
{
        if (child == -1)
        {
                free(input);
                perror("Error");
                exit(EXIT_FAILURE);
        }
}
