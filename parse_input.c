#include "libs.h"
/**
 * _isspace - checks for white space characters
 * @c: character to check
 * Return: 1 if c is a white space character, 0 otherwise
 */
int _isspace(char c)
{
	return (c == ' ' || c == '\t');
}
/**
 * parse_input - Tokenizes the input string and stores the tokens in args array
 * @input: The input string to be parsed
 * @args: The array to store the parsed tokens
 */
void parse_input(char *input, char **args)
{
	int i = 0;
	char *s;

	/* skip leading spaces */
	s = input;
	while (_isspace(*input) && *input)
		input++;

	if (!*input || *input == '\n')
	{
		free(s);
		args[0] = NULL;
		return;
	}
	args[i] = strdup(strtok(input, "\t \n"));
	while (args[i] != NULL && i < MAX_ARGS - 1)
	{
		i++;
		args[i] = strtok(NULL, "\t \n");
	}
	args[i] = NULL;
	free(s);
}
