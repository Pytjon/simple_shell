#include "shell.h"

/**
 * free_memory_buffers - Frees memory buffers.
 * @buffers: Array of buffers to be freed.
 *
 * Return: No return.
 */
void free_memory_buffers(char **buffers)
{
int index = 0;

if (!buffers || buffers == NULL)
	return;

while (buffers[index])
{
	free(buffers[index]);
	index++;
}

free(buffers);
}

