#include "libs.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *@fd:file descriptor
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int fd, char c)
{
	return (write(fd, &c, 1));
}



/**
 * _strlenc - Strlen function but applied for constant char pointer s
 * @s: Type char pointer
 * Return: c
 */
int _strlenc(const char *s)
{
	int c = 0;

	while (s[c] != '\0')
	{
		c++;
	}
	return (c);
}
