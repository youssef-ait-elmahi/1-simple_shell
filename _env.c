#include "libs.h"
/**
 * env - Prints the environment variables.
 * This function retrieves the environment variables
 * and prints them using the _printf function.
 * Return: void
 */
void env(void)
{
	char **envs;

	envs = __environ;
	while (*envs)
	{
		_printf(1, "%s\n", *envs);
		envs++;
	}
}
