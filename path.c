#include "libs.h"
/**
 * find_path - Finds and returns the value of the "PATH" environment variable
 * Return: A string containing the value of the "PATH" environment variable
 */
char *find_path()
{
	int i = 0;
	char *p = "PATH=";
	int lenp = strlen(p);

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], p, lenp) == 0)
			return (environ[i] + lenp);
	i++;
	}
	return (0);
}
