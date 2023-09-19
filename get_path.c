#include "shell.h"

/**
 * get_path - Get the full path of a command from PATH.
 * @cmd: The command to find in PATH.
 * Return: The full path of the command, or NULL if not found.
 */
char *get_path(char *cmd)
{
	char *env, *dr;
	int i;
	struct stat st;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (_strdup(cmd));
			return (NULL);
		}
	}
	env = _getenv("PATH");
	if (!env)
		return (NULL);

	dr = strtok(env, ":");

	while (dr)
	{
		char *f_cmd = malloc(strlen(cmd) + strlen(dr) + 2);

		if (f_cmd)
		{
			strcpy(f_cmd, dr);
			strcat(f_cmd, "/");
			strcat(f_cmd, cmd);
			if (stat(f_cmd, &st) == 0)
			{
				free(env);
				return (f_cmd);
			}
			free(f_cmd);
			dr = strtok(NULL, ":");
		}
	}
	free(env);
	return (NULL);
}
