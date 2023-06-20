#include "libs.h"
/**
 * run_cmd - Execute a command specified by the user
 * @line: The command line input
 * Return: 1 if command executed successfully, otherwise 0
 */
int run_cmd(char *line)
{
	char *path, **pathsp, *cmd = _strdup(line), **splitted;
	struct stat st;

	if (cmd == NULL)
		return (EXIT_FAILURE);
	splitted = split(cmd, "\t \n");
	free(cmd);
	if (splitted == NULL)
	{
		return (EXIT_FAILURE);
	}
	if (stat(splitted[0], &st) == 0)
	{
		execute_command(splitted[0], splitted);
			free_2d_array(splitted);
		return (1);
	}
	path = find_path();
	if (path == NULL)
	{
		return (EXIT_FAILURE);
	}
	cmd = _strdup(path);
	pathsp = split(cmd, ":");
	free(cmd);
	if (pathsp == NULL)
	{
		return (EXIT_FAILURE);
	}
	return (cmd_helper(pathsp, splitted));
}
