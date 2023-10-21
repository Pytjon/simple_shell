#include "shell.h"
/**
 *checker- It checks to see whether its a built in function,
 *@cmd: It tokenized user input,
 *@buf: Line derived from getline function,
 *Return: 1 if command executed 0 if cmd is not executed.
 */
int checker(char **cmd, char *buf)
{
	if (handle_builtin(cmd, buf))
		return (1);
	else if (**cmd == '/')
	{
		execution(cmd[0], cmd);
		return (1);
	}
	return (0);
}

