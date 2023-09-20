#include "shell.h"

/**
 * main - Simple shell function.
 *
 * This is the main function of a simple shell program. It reads user input,
 * tokenizes commands, and executes them in child processes.
 *
 * @ac: The argument count (not currently used).
 * @argv: The array of strings representing the program's arguments.
 *
 * Return: Always returns 0.
 */

int main(int ac, char *argv[])
{
	char *line = NULL;
	char **cmmd = NULL;
	int index = 0;
	int sts;
	(void)ac; /* Suppress unused argument warning */

	while (1)
	{
		line = r_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO,"\n", 1);
			return (sts);
		}
		index++;

		cmmd = tokenizer(line);

		if (cmmd == NULL)
                        continue;

		if (_strcmp(cmmd[0], "exit") == 0)
		{
			free_arry(cmmd);
			exit(sts);
		}

		sts = _exec(cmmd, argv, index);
	}
}
