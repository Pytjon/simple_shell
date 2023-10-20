#include "shell.h"

/**
 * execute_command - Executes user-entered commands.
 * @command_path: Command to be executed.
 * @command_args: Vector array of pointers to command arguments.
 *
 * Return: It returns 0.
 */
void execute_command(char *command_path, char **command_args)
{
pid_t child_pid;
int status;
char **environment = environ;

child_pid = fork();
if (child_pid < 0)
	perror(command_path);
if (child_pid == 0)
{
execve(command_path, command_args, environment);
perror(command_path);
free(command_path);
free_memory_buffers(command_args);
exit(98);
}
else
wait(&status);
}

