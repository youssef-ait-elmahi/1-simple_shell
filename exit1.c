#include "libs.h"
/**
 * my_exit - Frees memory and exits the program.
 * @input: Pointer to the input string.
 * @command: Pointer to the command string.
 * This function frees the memory allocated for the
 * input and command strings
 * and then exits the program with the status
 * returned by the status_exit() function.
 */

void my_exit(char *input, char *command)
{
	free(input);
	free(command);
	exit(exit_status(0, 0));
}
