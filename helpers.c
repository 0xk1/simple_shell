#include "shell.h"

/**
 * free_tokens - function that free the tokenized string
 * @tokens: tokens
 */
void free_tokens(char **tokens)
{
	int j;

	for (j = 0; tokens[j] != NULL; j++)
		free(tokens[j]);

	free(tokens);
}
