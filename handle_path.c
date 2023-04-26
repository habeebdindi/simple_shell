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
		fullpath = malloc(strlen(command) + 1);
		if (!fullpath)
			return (NULL);
		strcpy(fullpath, command);
		return (fullpath);
	}
	path = getenv("PATH");
	path_copy = malloc(strlen(path) + 1);
	if (!path_copy)
		return (NULL);
	strcpy(path_copy, path);
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		fullpath = malloc(strlen(command) + strlen(dir) + 2);
		if (!fullpath)
		{
			free(path_copy);
			return (NULL);
		}
		strcpy(fullpath, dir);
		strcat(fullpath, "/");
		strcat(fullpath, command);
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
