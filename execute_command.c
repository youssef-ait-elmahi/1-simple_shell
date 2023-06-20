#include "libs.h"
/**
 * execute_command - executes a command in a child process
 * @command: command to execute
 * @args: arguments for the command
 * Return: void
 */
void execute_command(char *command, char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(command, args, __environ) == -1)
		{
			perror("execve");
			exit(1);
		}
	}
	else
	{
			if (waitpid(pid, &status, 0) == -1)
			{
				perror("waitpid");
				exit(1);
			}
			exit_status(1, WEXITSTATUS(status));
	}
}
