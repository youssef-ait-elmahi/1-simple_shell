#include "libs.h"
/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 * Return: the length of the string
*/
int _strlen(char *s)
{
	int i = 0;

	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
