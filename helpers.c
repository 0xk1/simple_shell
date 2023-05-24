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
 * @input: the input
 * Return: return 0 if its blank or 1 if its not
*/
int check_blank(char *input)
{
	int i = 0;

	while (input[i] != '\n')
	{
		if (input[i] == ' ' || input[i] == '\t')
			i++;
		else
			return (1);
	}
	return (0);
}

/**
 * _setenv - set an environment variable
 * @name: variable name
 * @value: the new value
 * @overwrite: if overwrite = 0 the value will be overwritten
 * Return: return 0 on success -1 on any faillure
*/

int _setenv(char *name, char *value, int overwrite)
{
	char *env[50];
	char env_v[2000],env_g[2000];
	char eng[50][2000];
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
			env[0] = strenv(env_g, name, value);
		environ[i] = env[0];
		return (0);
	}
	if (tst == 0)
	{
		int ln = 0;
		/*getting env lengh*/
		while (environ[ln] != NULL)
			ln++;
		/**copying environ into env*/
		for (j = 0; environ[j] != NULL; j++)
			env[j] = _strcpy(eng[j], environ[j]);
		/**setting the new environemnt variable*/
		env[j] = strenv(env_v, name, value);
 		environ = env;
		return (0);
	}
	return (-1);
}

/**
 * _unset - unset a variable in environment
 * @name: variable name
 * Return: always 0
*/

int _unset(char *name)
{
	int i = 0, tst = 0;
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
		for (; environ[i] != NULL; i++)
			environ[i] = environ[i + 1];
	}
	return (0);
}


/**
 * handler_function - handler function
 * @i: i
 */
void handler_function(int i __attribute__((unused)))
{
	_puts("\n$ ", 1);
}
