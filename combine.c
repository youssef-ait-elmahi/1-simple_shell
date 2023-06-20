#include "libs.h"
/**
 * _combine_path - combines two strings into a single path
 * @s1: first string
 * @s2: second string
 * Return: pointer to new string
 */
char *_combine_path(const char *s1, const char *s2)
{
	size_t len1, len2;
	size_t iterator;
	char *new_string;

	len1 = strlen(s1);
	len2 = strlen(s2);
	new_string = malloc(sizeof(char) * (len1 + len2 + 2));
	if (!new_string)
		return (NULL);
	iterator = 0;
	while (iterator < len1)
	{
		new_string[iterator] = s1[iterator];
		iterator++;
	}
	new_string[iterator] = '/';
	iterator++;
	while (iterator - len1 - 1 < len2)
	{
		new_string[iterator] = s2[iterator - len1 - 1];
		iterator++;
	}
	new_string[iterator] = 0;
	return (new_string);
}
