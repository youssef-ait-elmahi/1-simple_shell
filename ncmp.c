#include "libs.h"
/**
 * _strncmp - Compare two strings
 * @s1: First string to compare
 * @s2: Second string to compare
 * @n: Maximum number of characters to compare
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	while (i < n)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
		{
			/* Reached the end of one or both strings */
			if (s1[i] == s2[i])
				return (0);
			else if (s1[i] < s2[i])
				return (-1);
			else
				return (1);
		}
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);

		i++;
	}
	return (0);
}
