#include "shell.h"
#include <signal.h>

/**
 * main - Entry point for a simple shell
 * @ac: Argument count
 * @args: Argument vector
 * @envp: Array of environment strings
 *
 * Return: Always 0 on success
 */
int main(__attribute__((unused))int ac, char **args, char **envp)
{
	char *line = NULL;
	pid_t pid;
	size_t len = 0;

	signal(SIGINT, SIG_IGN);

while (1)
{
/*Check if the shell is running in an interactive terminal*/
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "$ ", 2);
/*Read a line of input from the user*/
if (getline(&line, &len, stdin) == -1)
{
perror("getline");
exit(EXIT_FAILURE);
}
/*Tokenize the input line into arguments*/
args = tokenizer(line);
/*Check if a command was provided*/
if (args[0] != NULL)
{
if (check_builtin(args[0]))
{
/*Execute builtin command*/
handle_builtin(args, line);
}
else
{
/*create a child process to execute an external command*/
pid = fork();

if (pid == -1)
{
perror("Fork error");
close_program(args, line);
}
else if (pid == 0)
{
	if (_strcheck(args[0], '/'))
		args[0] = complete_path(args[0]);
	if (execve(args[0], args, envp))
	{
		perror(args[0]);
		close_program(args, line);
	}
}
else
{
/*wait for the child process to complete*/
wait_for_child_process(pid);
}
}
}
/*clean up memory*/
free(args);
free(line);
}
return (EXIT_SUCCESS);
}

/**
 * wait_for_child_process - wait for a child process to exit
 * @pid: process ID of the child
 */
void wait_for_child_process(pid_t pid)
{
	int status;
	pid_t wpid;

	do {
		wpid = waitpid(pid, &status, WUNTRACED);
	} while (wpid != pid && !WIFEXITED(status) && !WIFSIGNALED(status));
}

/**
 * close_program - frees memory and exit the program on error
 * @args: buffer containing the input tokenized
 * @line: buffer containing the command read from standard input
 */
void close_program(char **args, char *line)
{
	free(args);
	free(line);
	exit(EXIT_FAILURE);
}
