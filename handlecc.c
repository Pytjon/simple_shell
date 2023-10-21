#include "shell.h"

/**
* handle_builtin - It handles execution of builtin functions,
* @command: It tokenized commands,
* @line: Input read from standard input,
*
* Return: 1 if executed, 0 if not.
*/
int handle_builtin(char **command, char *line)
{
	struct builtin builtin = {"env", "exit"};

	if (_strcmp(*command, builtin.env) == 0)
	{
		print_env();
		return (1);
	}
	else if (_strcmp(*command, builtin.exit) == 0)
	{
		exit_cmd(command, line);
		return (1);
	}
	return (0);
}

