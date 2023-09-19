#include "shell.h"

/**
 * _getenv - Get the value of an environment variable.
 * @val: The name of the environment variable to retrieve.
 *
 * Return: If the environment variable exists, return its value.
 * Otherwise, return NULL.
 */

char *_getenv(char *val)
{
	char *key;
	char *result;
	char *dup;
	int i;

	while (environ[i])
	{
		dup = _strdup(environ[i]);
		key = strtok(dup, "=");
		if (_strcmp(key, val) == 0)
		{
			val = strtok(NULL, "\n");
			result = _strdup(val);
			free(dup), dup = NULL;
			return (result);
		}
		free(dup), dup = NULL;
		i++;
	}
	return (NULL);
}
