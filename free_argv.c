#include "shell.h"

void free_argv(char **argv)
{
	int i;

        for (i = 0; argv[i] != NULL; i++)
                free(argv[i]);
        free(argv);
}
