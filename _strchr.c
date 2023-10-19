#include "shell.h"

/**
 * _strcheck - locates a character in a string
 * @str: string to be cheeked
 * @c: character to be located
 *
 * Return: return poiinter to string or 0 if not found
 */

char *_strcheck(const char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (char *)str;
		str++;
	}
	if (!c)
		return (NULL);
	return (0);
}

