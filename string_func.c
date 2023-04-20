#include "shell.h"

/**
 * _strcpy - Copies string pointed to by source to dest.
 * @dest: Buffer to copy to.
 * @src: Buffer to copy from.
 *
 * Return: void.
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = src[i];

	return (dest);
}

/**
 * _strlen - Counts length of a string.
 * @s: The string.
 *
 * Return: length of the string.
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}
