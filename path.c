#include "shell.h"

/**
 * complete_path - generates a complete path from a command
 * @command: command to get a complete path from
 *
 * Return: complete path for the command
 */
char *complete_path(char *command)
{
	int i = 0;
	char *path, *token, *cwd, *temp[BUFFER_SIZE];
	struct stat st;
	char c = '/';

	cwd = getcwd(NULL, 0);
	path = get_environment_variable("PATH");
	token = strtok(path, ":");

	while (token != NULL)
	{
		temp[i++] = token;
		token = strtok(NULL, ":");
	}
	temp[i] = NULL;
	i = 0;
	while (temp[i] != NULL)
	{
		chdir(temp[i]);
		if (stat(command, &st) == 0)
		{
			temp[i] = _strncat(temp[i], &c, 1);
			command = _strcat(temp[i], command);
			break;
		}
		i++;
	}
	chdir(cwd);
	return (command);
}
