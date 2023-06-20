#include "libs.h"
/**
 * free_2d_array - frees a 2D array of characters
 * @ptr: pointer to the 2D array to be freed
 * Return: void
 */
void free_2d_array(char **ptr)
{
	int i;

	for (i = 0; ptr[i]; i++)
	{
		free(ptr[i]);
	}
	free(ptr);
}
