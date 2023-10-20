#include "shell.h"

/**
 * handle_exit_command - Handles the exit command.
 * @command_tokens: Tokenized command.
 * @input_line: Input read from standard input.
 *
 * Return: No return.
 */
void handle_exit_command(char **command_tokens, char *input_line)
{
free(input_line);
free_memory_buffers(command_tokens);
exit(0);
}

