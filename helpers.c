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
	char **env;
	int i = 0, tst = 0, j = 0;/*tst - test if "name" is a varibale path*/
	int namelen = _strlen(name);


	while (environ[i])
	{
		if (_strncmp(name, environ[i], namelen) == 0 && environ[i][namelen] == '=')
		{
			tst = 1;
			break;
		}
		i++;
	}
	if (tst == 1)
	{
		if (overwrite == 0)
			environ[i] = _strdup(string_concat(name, value, '='));
		return (0);
	}
	if (tst == 0)
	{
		int ln = 0;
		/*getting env lengh*/
		while (environ[ln] != NULL)
			ln++;
 		env = malloc(8 * (ln + 2));
		/*copying environ into env*/
  		for (;environ[j] != NULL; j++)
			env[j] = environ[j];
		/*setting the new environemnt variable*/
		env[j] = string_concat(name, value, '=');
		env[j + 1 ] = NULL;

		environ = env;

		return (0);
	}
	return (-1);
}
