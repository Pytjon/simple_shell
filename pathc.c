#include "shell.h"

/**
 * find_path - Search for PATH environ var in the global environment.
 * Return: NULL if PATH is not found, or the PATH string if found.
 */
char *find_path(void)
{
int index = 0;
char **env_var = environ;
char *path = NULL;

while (*env_var)
{
if (_strncmp(*env_var, "PATH=", 5) == 0)
{
path = *env_var;
while (*path && index < 5)
{
	path++;
	index++;
}
return (path);
}
env_var++;
}
return (NULL);
}


