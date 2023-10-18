#include "shell.h"

/**
 * check_builtin -  check if the given command is a built-in function
 * @command: tokenized input command
 *
 * Return: 1 if the command is builtin, 0 if it is not
 */
int check_builtin(char *command)
{
	if (_strcmp(command, "cd") == 0 || _strcmp(command, "exit") == 0)
		return (1);
	return (0);
}

/**
 * handle_builtin - handles the execution of a builtin command
 * @args: command arguments that are tokenized
 * @line: buffer where the command from stdin is read
 *
 * Description: this function executes builtin commands like "cd" and "exit"
 * if the "exit" command is called,
 * it frees allocated memory and exits the shell
 *
 * Return: 1 if it is executed, 0 if not
 */
void handle_builtin(char **args, char *line)
{
	if (_strcmp(args[0], "cd") == 0)
	{
		if (args[1] ==  NULL)
			print_error_message(args[0], ":missing argument\n");
		else if (chdir(args[1]) != 0)
			perror(args[0]);
	}
	else if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
		{
			int status = string_to_int(args[1]);

			if (status == 0)
			{
				close_program(args, line);
			}
			free(args);
			free(line);
			exit(status);
		}
		free(args);
		free(line);
		exit(EXIT_SUCCESS);
	}
}
