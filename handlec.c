#include "shell.h"

/**
 * handle_builtin_commands - Handles execution of built-in commands.
 * @command_tokens: Tokenized commands.
 * @input_line: Input read from standard input.
 *
 * Return: 1 if a built-in command is executed, 0 if not.
 */
int handle_builtin_commands(char **command_tokens, char *input_line)
{
struct builtin builtins = {"env", "exit"};

if (_strcmp(*command_tokens, builtins.env) == 0)
{
	print_environment();
	return (1);
}
else if (_strcmp(*command_tokens, builtins.exit) == 0)
{
handle_exit_command(command_tokens, input_line);
return (1);
}
return (0);
}

