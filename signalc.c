#include "shell.h"

/**
 * handle_signal - Handles signals and keeps track of interactive mode.
 * @signal_number: The signal number.
 *
 * Returns: Nothing.
 */
void handle_signal(int signal_number)
{
(void)signal_number;
write(STDERR_FILENO, "\n", 1);
write(STDERR_FILENO, "$ ", 2);
}

