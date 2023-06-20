#include "libs.h"
/**
 * cmd_helper - helper function for command execution
 * @pathsp: array of paths to search for command
 * @splitted: array of command and arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int cmd_helper(char **pathsp, char **splitted)
{
	int i = 0;
	char *full_cmd;
	struct stat st;

	while (pathsp[i])
	{
		full_cmd = _combine_path(pathsp[i], splitted[0]);
		if (stat(full_cmd, &st) == 0)
		{
			execute_command(full_cmd, splitted);
			free(full_cmd);
			free_2d_array(pathsp);
			free_2d_array(splitted);
			return (EXIT_SUCCESS);
		}
		i++;
		free(full_cmd);
	}
	_printf(2, "command not found\n");
	exit_status(1, 127);
	/*_printf("sh: %d: %s: not found", ,input);*/
	free_2d_array(pathsp);
	free_2d_array(splitted);
	return (EXIT_FAILURE);
}
