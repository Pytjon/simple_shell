#include "shell.h"

/**
 * string_to_int - function that converts a string to an integer
 * @str: the string to be converted
 *
 * Return: the integer value, or 0 on error
 */
int string_to_int(const char *str)
{
	int answer = 0;
	int sign = 1;
	int i = 0;

	if (str == NULL || str[0] == '\0')
	{
		/*handle empty or NULL string as an error*/
		return (0);
	}

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			/*non-digit character encountered, return 0 as an error*/
			return (0);
		}
		if (answer > (INT_MAX - (str[i] - '0')) / 10)
		{ /* Integer overflow will occur if we add the next digit */
			return (0);  /* Or another appropriate error code */
		}

		/*update the result by multiplying by 10 and assing the digit*/
		answer = answer * 10 + (str[i] - '0');
	}
	/*multiply the result by the sign to get the final integer value*/
	return (sign * answer);
}
