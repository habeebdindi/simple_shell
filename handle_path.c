#include "shell.h"

char *getpath(char *command)
{
	char *path, *path_copy, *dir, *fullpath;

	if (!command)
		return (NULL);
	path = getenv("PATH");
	path_copy = malloc(strlen(path) + 1);
	if (!path_copy)
		return (NULL);
	strcpy(path_copy, path);
	dir = strtok(path_copy, ":");
	while(dir != NULL)
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
