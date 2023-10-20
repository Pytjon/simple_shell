#include "shell.h"

/**
 * check_builtin - Checks if it's a built-in function.
 * @command_tokens: Tokenized user input.
 * @input_line: Line derived from getline function.
 *
 * Return: 1 if a built-in command is executed, 0 if not.
 */
int check_builtin(char **command_tokens, char *input_line)
{
if (handle_builtin_commands(command_tokens, input_line))
	return (1);
else if (**command_tokens == '/')
{
execute_command(command_tokens[0], command_tokens);
return (1);
}
return (0);
}

