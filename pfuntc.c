#include "shell.h"

/**
 * write_character - Writes a character to standard output.
 * @character: The character to print.
 *
 * Return: On success, it returns 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int write_character(char character)
{
return (write(1, &character, 1));
}

/**
 * print_string - Prints a string.
 * @str: The string to be printed.
 *
 * Return: The number of characters printed.
 */
int print_string(char *str)
{
int index = 0;

while (str[index] != '\0')
{
write_character(str[index]);
index++;
}

return (index);
}

