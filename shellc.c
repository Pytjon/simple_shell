#include "shell.h"

/**
 * main - Implements the read, execute, and print loop.
 * @argc: Argument count.
 * @argv: Argument vector.
 * @envp: Environment vector.
 *
 * Return: It returns 0.
 */
int main(int argc, char **argv, char *envp[])
{
char *input_line = NULL, *full_command_path = NULL, *path_environment = NULL;
size_t buffer_size = 0;
ssize_t line_size = 0;
char **command_tokens = NULL, **path_tokens = NULL;

(void)envp, (void)argv;

if (argc < 1)
	return (-1);

signal(SIGINT, handle_signal);

while (1)
{
	free_memory_buffers(command_tokens);
	free_memory_buffers(path_tokens);
	free(full_command_path);
	display_prompt();
	line_size = getline(&input_line, &buffer_size, stdin);
	if (line_size < 0)
		break;
	info.ln_count++;
	if (input_line[line_size - 1] == '\n')
		input_line[line_size - 1] = '\0';
	command_tokens = tokenize_input(input_line);
	if (command_tokens == NULL || *command_tokens == NULL || **command_tokens == '\0')
		continue;
	if (check_builtin(command_tokens, input_line))
		continue;
	path_environment = find_path();
	path_tokens = tokenize_input(path_environment);
	full_command_path = validate_path(path_tokens, command_tokens[0]);
	if (!full_command_path)
		perror(argv[0]);
	else
		execute_command(full_command_path, command_tokens);
}

if (line_size < 0 && flags.interactive)
write(STDERR_FILENO, "\n", 1);

	free(input_line);
	return (0);
}


