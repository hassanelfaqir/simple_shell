#include "shell.h"

/**
 * free_arry - Free memory allocated for an array of strings.
 *
 * This function takes an array of strings 'ar' and frees the memory
 * allocated for each string element and the array itself.
 *
 * @ar: The array of strings to be freed.
 */

void free_arry(char **ar)
{
	int i;

	if (!ar)
		return;

	for (i = 0; ar[i]; i++)
	{
		free(ar[i]);
		ar[i] = NULL;
	}
	free(ar), ar = NULL;
}

/**
 * p_error - Print an error message.
 * @nm: The program name.
 * @cmd: The command that caused the error.
 * @index: The command index.
 */

void p_error(char *nm, char *cmd, int index)
{
	char *idx = intToString(index);
	char *msg = ": not found\n";

	write(STDERR_FILENO, nm, _strlen(nm));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));
	free(idx);
}
