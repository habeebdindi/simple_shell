#include "shell.h"

/**
 * getpath - gets the full path of a file.
 * @command: array which holds the command typed by user.
 * Return: char pointer
 */
char *getpath(char *command)
{
	char *path, *path_copy, *dir, *fullpath;

	if (!command)
		return (NULL);
	if (access(command, F_OK) == 0)
	{
		fullpath = malloc(_strlen(command) + 1);
		if (!fullpath)
			return (NULL);
		_strcpy(fullpath, command);
		return (fullpath);
	}
	path = getenv("PATH");
	path_copy = malloc(_strlen(path) + 1);
	if (!path_copy)
		return (NULL);
	_strcpy(path_copy, path);
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		fullpath = malloc(_strlen(command) + _strlen(dir) + 2);
		if (!fullpath)
		{
			free(path_copy);
			return (NULL);
		}
		_strcpy(fullpath, dir);
		_strcat(fullpath, "/");
		_strcat(fullpath, command);
		if (access(fullpath, F_OK) == 0)
		{
			free(path_copy);
			return (fullpath);
		}
		free(fullpath);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

/**
 * err_clean - prints error message and cleans up if a command doesn't exist.
 * @i: pointer to the current shell iteration.
 * @av0: the name of the shell program.
 * @argv: parsed user input.
 * @input: user input to shell.
 * Return: void.
 */
void err_clean(int *i, char *av0, char *input, char **argv, int *status)
{
	char err_msg[200];

	_memset(err_msg, 0, sizeof(err_msg));
	sprintf(err_msg, "%s: %d: %s: not found", av0, *i, argv[0]);
	write(STDERR_FILENO, err_msg, strlen(err_msg));
	write(STDERR_FILENO, "\n", _strlen("\n"));
	free(argv);
	free(input);
	if (!isatty(0))
		*status = 127;
}
