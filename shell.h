#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

/* environment variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/* handle built ins */
int check_builtin(char **command_token, char *input_line);
void display_prompt(void);
void handle_signal(int signal_number);
char **tokenize_input(char *input_line);
char *validate_path(char **path_tokens, char *command);
char *append_path(char *path, char *command);
int handle_builtin_commands(char **command_tokens, char *input_line);
void handle_exit_command(char **command_tokens, char *input_line);

void print_environment(void);

/* string handlers */
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *s);
char *_strchr(char *s, char c);

void execute_command(char *command_path, char **command_args);
char *find_path(void);

/* helper function for efficient free */
void free_memory_buffers(char **buffers);

struct builtin
{
	char *env;
	char *exit;
} builtin;

struct info
{
	int final_exit;
	int ln_count;
} info;

struct flags
{
	bool interactive;
} flags;

#endif /* SHELL_H */

