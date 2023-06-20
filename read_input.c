#include "libs.h"
/**
 * read_input - Reads a line of input from the user
 * @input: Pointer to a string to store the input
 */
void read_input(char *input)
{
	size_t bufsize = 0;
	ssize_t characters = getline(&input, &bufsize, stdin);

	if (characters == -1)
	{
		write(1, "\n", 1);
		exit(0);
	}
}
