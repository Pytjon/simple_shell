#include "shell.h"

/**
 * print_environment - Prints the environment variables to stdout.
 *
 * Return: It returns 0.
 */
void print_environment(void)
{
int index = 0;
char **env_var = environ;

while (env_var[index])
{
write(STDOUT_FILENO, (const void *)env_var[index], _strlen(env_var[index]));
write(STDOUT_FILENO, "\n", 1);
index++;
}
}


