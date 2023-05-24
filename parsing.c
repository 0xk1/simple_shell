#include "shell.h"

/**
 * parsing - function that tokonize a string
 * @input: string to tokenize
 * @delimiter: delimiter
 * Return: Array of tokens
 */
char **parsing(char *input, char *delimiter)
{
	char *input_copy, *token;
	char **tokens;
	int num_tokens = 0, i = 0;

	input_copy = _strdup(input);

	if (!input_copy)
		return (NULL);

	token = _strtok(input, delimiter);

	while (token)
	{
		num_tokens++;
		token = _strtok(NULL, delimiter);
	}
	num_tokens++;

	tokens = malloc(sizeof(char *) * num_tokens);

	if (!tokens)
	{
		perror("malloc() failed");
		return (NULL);
	}

	token = _strtok(input_copy, delimiter);

	while (token)
	{
		tokens[i] = _strdup(token);

		token = _strtok(NULL, delimiter);
		i++;
	}
	tokens[i] = NULL;

	free(input_copy);

	return (tokens);
}


