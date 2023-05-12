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

/**
 * check_blank - check if a string is made of only blank spaces
 * @imput : the imput
 * Return: return 0 if its blank or 1 if its not
*/
int check_blank(char *inmput)
{
	int i = 0;
	while (inmput[i] != '\n')
	{
		if (inmput[i] == ' ' || inmput[i] == '\t')
			i++;
		else
			return (1);
	}
	return (0);
}
