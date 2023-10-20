#include "shell.h"

/**
* append_path - Concatenates path and command.
* @path: The path component.
* @command: The command to be appended to the path.
*
* Return:  buffer containing  path and command on success,
* or NULL on failure.
*/
char *append_path(char *path, char *command)
{
char *result;/* The combined path and command.*/
size_t path_length = 0;/* Length of the path.*/
size_t command_length = 0;/* Length of the command.*/
size_t i = 0;
size_t j = 0;

if (command == NULL)
	command = "";

if (path == NULL)
	path = "";

path_length = _strlen(path);
command_length = _strlen(command);

result = malloc(sizeof(char) * (path_length + command_length + 2));
if (!result)
	return (NULL);

while (path[i])
{
	result[i] = path[i];
	i++;
}

if (path[i - 1] != '/')
{
result[i] = '/';
i++;
}

while (command[j])
{
	result[i + j] = command[j];
	j++;
}

result[i + j] = '\0';
return (result);
}


