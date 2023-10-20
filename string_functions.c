#include "shell.h"

/**
 * _strcat - a function that concatenates two strings.
 * @destination: The destination string.
 * @source: The source string to append.
 *
 * Return: Pointer to the concatenated string.
 */
char *_strcat(char *destination, const char *source)
{
	char *temp = destination;
	size_t destination_size;
	size_t source_size;

	while (*temp != '\0')
	{
		temp++;
	}

	destination_size = _strlen(destination);
	source_size = _strlen(source);

	if (destination_size + source_size > BUFFER_SIZE)
	{
		/*handling error*/
		return (NULL);
	}
	while (*source != '\0')
	{
	*temp = *source;
		temp++;
		source++;
	}

	*temp = '\0';

return (destination);
}


/**
*_strcmp - function that compares two strings.
*@s1: First string
*@s2: Second string
*
*Return: Difference between both strings.
*/
int _strcmp(const char *s1, const char *s2)
{
	int result;

	while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	result = (*s1 - *s2);

return (result);
}


/**
*_strncmp - Function that compares two strings with n number of characters
*@str1: First string
*@str2: Second string
*@n: Number of characters to compare
*
*Return: The difference between both strings or NULL
*/
int _strncmp(const char *str1, const char *str2, int  n)
{
	int i;

	for (i = 0; str1[i] && str2[i] && i < n; i++)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	if (i == n)
	return (0);

	return (str1[i] - str2[i]);

}


/**
* _strlen - function to get the length of a string
* @s: string to be counted
*
* Return: returns the total length of the string
*/
int _strlen(const char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}


/**
 * _strncat - Concatenate two strings with a given limit to the length
 *
 * @destination: The destination string.
 * @source: The source string.
 * @n: The maximum length to concatenate.
 *
 * Return: A pointer to the resulting string.
 */

char *_strncat(char *destination, char *source, int n)
{
	int i, j;

	for (i = 0; destination[i] != '\0'; i++)
	{
		/* No need to countinue */
	}
	for (j = 0; source[j] != '\0' && j < n; j++)
	{
		destination[i + j] = source[j];
	}
	destination[i + j] = '\0';
	return (destination);
}

