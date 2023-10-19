#include "shell.h"
#include <unistd.h>

/**
 * print_error_message - function that prints  err msg to standard err stream
 * @program_name: The name of the program
 * @message: The error message to be printed
 */

void print_error_message(const char *program_name, const char *message)
{
	const int stderr_fd = STDERR_FILENO;

	write(stderr_fd, program_name, _strlen(program_name));
	write(stderr_fd, message, _strlen(message));
}

