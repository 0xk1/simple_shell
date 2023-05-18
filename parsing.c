#include "shell.h"


/**
 * tok_counter - count number of tokens
 * @line : the string
 * @delimiter : delimiter
 * Return: number of tokens
*/
int tok_counter(char *line, char *delimiter)
{
	char *line_copy, *token;
	int num_tokens = 0;

	line_copy = _strdup(line);
	token = strtok(line_copy, delimiter);
	while (token)
	{
		num_tokens++;
		token = strtok(NULL, delimiter);
	}
	free(line_copy);
	return (num_tokens);
}
/**
 * parsing - function that tokonize a string
 * @input: string to tokenize
 * @delimiter : the delimiter
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
	num_tokens = tok_counter(input, delimiter);
	if (num_tokens == 0)/*to handle empty or \n \t string*/
	{
		tokens = malloc(8 * 2);
		if (!tokens)
		{
			perror("malloc() failed");
			return (NULL);
		}
		tokens[0] =  _strdup("\t\t\t");
		tokens[1] = NULL;
		return (tokens);
	}
	tokens = malloc(sizeof(char *) * (num_tokens + 1));
	if (!tokens)
	{
		perror("malloc() failed");
		return (NULL);
	}
	token = strtok(input_copy, delimiter);
	while (token)
	{
		tokens[i] = _strdup(token);
		token = strtok(NULL, delimiter);
		i++;
	}
	tokens[i] = NULL;
	free(input_copy);
	return (tokens);
}
