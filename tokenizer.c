#include "shell.h"

/**
 * tokenizer - create an array of tokens from a string
 * @line: the input string to be tokenized
 *
 * Return: return an array of tokens
 */
char **tokenizer(char *line)
{
	int bufsize = MAX_ARGS;
	int index = 0;
	char *token, **tokens;
	char **temp;

	if (line == NULL)
		exit(EXIT_FAILURE);
	tokens = (char **) malloc(bufsize * sizeof(char *));
	if (!tokens)
	{
		perror("In Tokenize, Malloc");
		free(line);
		exit(EXIT_FAILURE);
	}
	token = strtok(line, "\t\r\n\a");
	while (token != NULL)
	{
		tokens[index++] = token;
		token = strtok(NULL, "\t\r\n\a");

		if (index >= bufsize)
		{
			bufsize += MAX_ARGS;
			temp  = (char **)realloc(tokens, bufsize * sizeof(char *));

			if (!temp)
			{
				perror("In Tokenize, Realloc");
				free(line);
				exit(EXIT_FAILURE);
			}
			tokens = temp;
		}
	}
	tokens[index] = NULL;

	return (tokens);
}
