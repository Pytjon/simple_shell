#include "shell.h"

/**
 * get_environment_variable - function to get value of an enviro variable
 * @var_name: Name of the environment variable.
 *
 * Return: The value of the environment variable or NULL if it is not found.
 */

char *get_environment_variable(const char *var_name)
{
	size_t i;
	size_t name_length = _strlen(var_name);

	if (var_name == NULL || environ == NULL)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], var_name, name_length) == 0
				&& environ[i][name_length] == '=')
			return (environ[i] + name_length + 1);
	}
	return (NULL);
}

