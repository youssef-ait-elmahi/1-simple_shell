#include "libs.h"
/**
 * executable - Executes the appropriate action based on the command.
 * @input: Pointer to the input string.
 * @command: Pointer to the command string.
 * Return: void
 */
void  executable(char *input, char *command)
{
	if (_strcmp(command, "exit") == 0)
		my_exit(input, command);
	else if (_strcmp(command, "env") == 0)
		env();
	else
		run_cmd(input);
}
/**
 * main - Entry point of the program
 * Return: Always 0 (success)
 */
int main(void)
{
	char *input;
	char *args[MAX_ARGS];
	size_t bufsize = 0;
	ssize_t characters;

	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	while (1)
	{
		prompt();
		input = NULL;
		characters = getline(&input, &bufsize, stdin);
		if (characters == -1)
		{
			free(input);
			exit(0);
		}
		if (!*(input + 1))
		{
			free(input);
			continue;
		}
		parse_input(_strdup(input), args);
		if (!args[0])
		{
			free(input);
			continue;
		}
		executable(input, args[0]);
		free(args[0]);
		free(input);
		input = NULL;
		bufsize = 0;
	}
	return (exit_status(0, 0));
}
