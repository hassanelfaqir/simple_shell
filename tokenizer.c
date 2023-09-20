#include "shell.h"

/**
 * tokenizer - Tokenizes a string into an array of strings.
 * @line: The input string to tokenize.
 * Return: An array of tokens (strings).
 */

char **tokenizer(char *line)
{
	char *token;
	char *tmp = NULL;
	char **cmd = NULL;
	int token_count = 0;
	int i = 0;

	if (!line)
		return (NULL);

	tmp = _strdup(line);
	token = strtok(tmp, DELIM);
	if (token == NULL)
	{
		free(tmp), tmp = NULL;
		free(line), line = NULL;
		return (NULL);
	}
	while (token)
	{
		token_count++;
		token = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;
	cmd = malloc(sizeof(char *) * (token_count + 1));
	if (!cmd)
	{
		free(line), line = NULL;
		return (NULL);
	}
	token = strtok(line, DELIM);
	while (token)
	{
		cmd[i] = _strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	free(line), line = NULL;
	cmd[i] = NULL;
	return (cmd);
}
