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

/**
 * _setenv - set an environment variable
 * @name : variable name
 * @value : the new value
 * @overwrite : if overwrite = 0 the value will be overwritten
 * @Return: return 0 on success -1 on any faillure
*/

int _setenv(char *name, char *value, int overwrite)
{
	char **env = environ;
	int i = 0, tst = 0;
	int namelen = _strlen(name);

	while (env[i])
	{
		if (_strncmp(name, env[i], namelen) == 0 && env[i][namelen] == '=')
			tst = 1;
		i++;
	}
	if (tst == 1)
	{
		if (overwrite == 0)
			environ[i] = string_concat(name, value, '=');
		return (0);
	}
	if (tst != 1)
	{
		return(-1);/*i'll code it later*/
	}
	return (-1);
}