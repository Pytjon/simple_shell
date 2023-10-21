#include "shell.h"

/**
* free_buffers - It frees buffers,
* @buf: Buffer to be freed,
*
* Return: No return.
*/
void free_buffers(char **buf)
{
	int i = 0;

	if (!buf || buf == NULL)
		return;
	while (buf[i])
	{
		free(buf[i]);
		i++;
	}
	free(buf);
}

