#include "shell.h"

/**
 * _exec - Execute a command.
 * @cmd: The command and its arguments as an array.
 * @argv: The program's argv.
 * @index: The command index.
 * Return: The exit status of the command.
 */
int _exec(char **cmd, char **argv, int index)
{
	char *f_cmd;
	pid_t child_pid;
	int sts;

	f_cmd = get_path(cmd[0]);
	if (!f_cmd)
	{
		p_error(argv[0], cmd[0], index);
		free_arry(cmd);
		return (127);
	}

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(f_cmd, cmd, environ) == -1)
		{
			free(f_cmd), f_cmd =NULL;
			free_arry(cmd);
		}
	}
	else
	{
		waitpid(child_pid, &sts, 0);
		free_arry(cmd);
		free(f_cmd), f_cmd = NULL;
	}
	return (WEXITSTATUS(sts));
}
