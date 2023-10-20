#include "shell.h"

/**
 * getline - read characters from the command line
 *
 * Return: a pointer to the memory address where the read characters are stored
 */
char *readline(void)
{
	size_t bufsize = BUFFER_SIZE;
	size_t index = 0;
	ssize_t count;
	char *temp, *buffer = (char *)malloc(sizeof(char) * bufsize);

	if (buffer == NULL)
	{
		perror("In readline, malloc");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		count = read(STDIN_FILENO, buffer + index, bufsize - index);
		if (count <= 0)
		{
			break;
		}
		index += count;

		if (buffer[index - 1] == '\n')
		{
			break;
		}
		if (index >= bufsize - 1)
		{
			bufsize += BUFFER_SIZE;
			temp = (char *)realloc(buffer, bufsize);
			if (temp == NULL)
			{
				perror("In readline, realloc");
				free(buffer);
				exit(EXIT_FAILURE);
			}
			buffer = temp;
		}
	}
		if (index == 0)
		{
			free(buffer);
			return (NULL);
		}
	buffer[index] = '\0';
	return (buffer);
}
