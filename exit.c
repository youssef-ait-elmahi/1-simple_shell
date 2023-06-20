/**
 * exit_status - Manages the exit status for a given action and new status
 * @action: The action to perform (1 for set, 0 for get)
 * @new_status: The new status to set
 * Return: The current exit status if action is 0,
 * or the new status if action is 1
 */
int exit_status(int action, int new_status)
{
	static int status;

	if (action == 1)
		status = new_status;
	return (status);
}
