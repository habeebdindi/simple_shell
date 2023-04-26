#include "shell.h"

/**
 * getpath - gets the full path of a file.
 * @command: array which holds the command typed by user.
 * Return: char pointer
 */
char *getpath(char *command)
{
	char *path, *path_copy, *dir, *fullpath;

	/* Check if the command is already a full path */
	if (access(command, F_OK) == 0)
	{
		/* Command is already a full path */
		fullpath = malloc(strlen(command) + 1);
		if (!fullpath)
			return (NULL);
		strcpy(fullpath, command);
		return (fullpath);
	}
	/* Command is not a full path, search for it in PATH directories */
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
