#include "shell.h"

/**
 * r_line - Read a line of input from the user.
 *
 * This function prompts the user for input, reads a line from standard input,
 * and dynamically allocates memory for the input.
 *
 * Return: A pointer to the string containing the user's input,or NULL on error
 */

char *r_line(void)
{
	char *line = NULL;
	char *promt = "$ ";
	size_t len = 0;
	ssize_t read;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, promt, 2);

	read = getline(&line, &len, stdin);

	if (read == -1)
	{
		free(line), line = NULL;
		return (NULL);
	}
	return (line);
}
