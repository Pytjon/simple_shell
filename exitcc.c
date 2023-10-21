#include "shell.h"

/**
* exit_cmd - It handles the exit command,
* @command: It tokenized command,
* @line: Input read from standard input,
*
* Return: no return.
*/
void exit_cmd(char **command, char *line)
{
	free(line);
	free_buffers(command);
	exit(0);
}

