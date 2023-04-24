#include "shell.h"

char **parser(char *input)
{
        char *in_copy, *token, **argv;
        int i, j;

        input[strcspn(input, "\n")] = '\0';
        in_copy = strdup(input);
        if (!in_copy)
		return (NULL);

        token = strtok(in_copy, " ");
        for (i = 1; token != NULL; i++)
                token = strtok(NULL, " ");
        free(in_copy);

        argv = malloc(sizeof(char *) * (i + 1));
        if (!argv)
		return (NULL);

        token = strtok(input, " ");
        for (i = 0; token != NULL; i++)
        {
                argv[i] = malloc(strlen(token) + 1);
                if (!argv[i])
                {
                        for (j = i - 1; j >= 0; j--)
                                free(argv[j]);
                        free(argv);
        		return (NULL);
                }
                strcpy(argv[i], token);
                token = strtok(NULL, " ");
        }
        argv[i] = NULL;
	return (argv);
}

void execute_command(char **argv, char *av0, char *input)
{
	char **envp = {NULL};

        execve(argv[0], argv, envp);
        perror(av0);
        free_argv(argv);
        free(input);
        exit(EXIT_FAILURE);
}
