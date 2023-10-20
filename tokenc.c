#include "shell.h"

/**
 * tokenize_input - Tokenizes the input line.
 * @input_line: The line to be tokenized.
 *
 * Returns: An array of strings (tokens).
 */
char **tokenize_input(char *input_line)
{
char *line_copy = NULL, *line_copy_ptr = NULL;
char *current_token = NULL, *delimiter = " \t\r\n";
char **tokens = NULL;
int token_count = 1;
size_t token_index = 0, delimiter_flag = 0;

line_copy = _strdup(input_line);
if (!line_copy)
	return (NULL);

line_copy_ptr = line_copy;

while (*line_copy_ptr)
{
if (_strchr(delimiter, *line_copy_ptr) != NULL && delimiter_flag == 0)
{
	token_count++;
	delimiter_flag = 1;
}
else if (_strchr(delimiter, *line_copy_ptr) == NULL && delimiter_flag == 1)
delimiter_flag = 0;

line_copy_ptr++;
}

tokens = malloc(sizeof(char *) * (token_count + 1));
current_token = strtok(line_copy, delimiter);

while (current_token)
{
tokens[token_index] = _strdup(current_token);
if (tokens[token_index] == NULL)
{
	free(tokens);
	return (NULL);
}
current_token = strtok(NULL, delimiter);
token_index++;
}

tokens[token_index] = NULL;
free(line_copy);
return (tokens);
}

