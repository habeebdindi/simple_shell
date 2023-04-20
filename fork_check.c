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

void fork_pass(char *input, char *av0)
{
        char *in_copy, *token, **argv, **envp = {NULL};
        int i, j;

        input[strcspn(input, "\n")] = '\0';
        in_copy = strdup(input);
        if (!in_copy)
        {
                free(input);
                exit(EXIT_FAILURE);
        }
        token = strtok(in_copy, " ");
        for (i = 1; token != NULL; i++)
                token = strtok(NULL, " ");
        free(in_copy);
        argv = malloc(sizeof(char *) * (i + 1));
        if (!argv)
        {
                free(input);
                exit(EXIT_FAILURE);
        }
        token = strtok(input, " ");
        for (i = 0; token != NULL; i++)
        {
                argv[i] = malloc(strlen(token) + 1);
                if (!argv[i])
                {
                        for (j = i - 1; j >= 0; j--)
                                free(argv[j]);
                        free(argv);
                        free(input);
                        exit(EXIT_FAILURE);
                }
                strcpy(argv[i], token);
                token = strtok(NULL, " ");
        }
        argv[i] = NULL;
        execve(argv[0], argv, envp);
        perror(av0);
        for (i = 0; argv[i] != NULL; i++)
                free(argv[i]);
        free(argv);
        free(input);
        exit(EXIT_FAILURE);
}
