#include "shell.h"

/**
 * validate_path - Checks if the path is valid for the given command.
 * @path_tokens: Tokenized path.
 * @command: User-entered command.
 *
 * Return: The path appended with the command on success, or NULL on failure.
 */
char *validate_path(char **path_tokens, char *command)
{
int index = 0;
char *result;

while (path_tokens[index])
{
result = append_path(path_tokens[index], command);
if (access(result, F_OK | X_OK) == 0)
	return (result);
free(result);
index++;
}
return (NULL);
}

