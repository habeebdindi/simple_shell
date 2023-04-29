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

/**
 * itoa - convert integer to string.
 * @i: the integer to be converted.
 * @b: a buffer to hold the converted integer.
 *
 * Return: a pointer to b.
 */
char *itoa(int i, char b[])
{
	char const digit[] = "0123456789";
	char *p = b;
	int shifter;

	if (!b || i < 1)
		return (NULL);
	if (i < 0)
	{
		*p++ = '-';
		i *= -1;
	}
	shifter = i;
	do { /* //Move to where representation ends */
		++p;
		shifter = shifter / 10;
	} while (shifter);
	*p = '\0';
	do { /* //Move back, inserting digits as u go */
		*--p = digit[i % 10];
		i = i / 10;
	} while (i);
	return (b);
}

/**
 * _atoi - conv string to char.
 * @str: the string to convert to char.
 * Return: the converted integer, if it can't be conv, 0.
 */
int _atoi(const char *str)
{
	int sign = 1;
	int num = 0;

	while (*str == ' ')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (sign * num);
}
