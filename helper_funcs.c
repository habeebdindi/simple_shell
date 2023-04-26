#include "shell.h"

/**
 * _memset - fills the first n bytes of the memory area pointed to by a pointer
 * @s: pointer to memory are.
 * @b: character to fill memory area with.
 * @n: number of bytes to fill
 *
 * Return: pointer to s.
 */

char *_memset(char *s, char b, unsigned int n)
{
	char *ptr = s;

	*ptr = b;
	while (n--)
		*ptr++ = b;
	return (s);
}
