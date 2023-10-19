#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 64
#define BUFFER_SIZE 1024

extern char **environ;

void wait_for_child_process(pid_t pid);
char **tokenizer(char *line);
char *_strcheck(const char *str, char c);
char *_strncat(char *destination, char *source, int n);
int _strlen(const char *s);
int _strncmp(const char *str1, const char *str2, int  n);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *destination, const char *source);
char *complete_path(char *command);
char get_environment_variable(const char *var_name);
void print_error_message(const char *program_name, const char *message);
void handle_builtin(char **args, char *line);
int check_builtin(char *command);
char *readline(void);
int string_to_int(const char *str);
void close_program(char **args, char *line);
void parse_args(char *line, char **args);


#endif
