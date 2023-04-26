#include "shell.h"
/**
 * parser - splits the input string
 * @input: pointer to a string
 * Return: pointer to a pointer to an array of strings
 */
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
	if (!argv)
	{
		free(input);
		return (NULL);
	}
	return (argv);
}

void execute_command(char **argv, char *av0, char *input, char *c)
{
	int status;
	pid_t child;

	child = fork();

	forkcheck_fail(child, input);
	if (child == 0)
	{
		argv[0] = c;
		execve(argv[0], argv, environ);
	        perror(av0);
	        free_argv(argv);
	        free(input);
	        exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
		free(c);
		free_argv(argv);
        }
}

void print_env(char **env)
{
	while (*env != NULL)
	{
		printf("%s\n", *env++);
	}
}
