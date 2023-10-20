#include "shell.h"

/**
 * display_prompt - Displays a prompt ($ or other) for user input.
 *
 * Return: No return value.
 */
void display_prompt(void)
{
if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
flags.interactive = 1;

if (flags.interactive)
write(STDERR_FILENO, "$ ", 2);
}

