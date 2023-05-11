#include "shell.h"

/**
 * _getenv - getenv
 * @name: variable name
 * Return: null or value
 */

char *_getenv(char *name)
{
	char **env = environ;
	int i = 0;
	size_t namelen = _strlen(name);

	while (env[i])
	{
		if (_strncmp(name, env[i], namelen) == 0 && env[i][namelen] == '=')
			return (&env[i][namelen + 1]);
		i++;
	}

	return (NULL);
}
/**
 * path_concat - concat two strings
 * @str1: string 1
 * @str2: string 2
 * Return: str1/str2
 */

char *path_concat(char *str1, char *str2)
{
	size_t s1_len, s2_len, i = 0, j = 0;
	char *result;

	s1_len = _strlen(str1);
	s2_len = _strlen(str2);
	result = malloc(s1_len + s2_len + 2);

	if (!result)
		return (NULL);
	while (str1[i])
	{
		result[i] = str1[i];
		i++;
	}

	result[i] = '/';
	i++;

	while (str2[j])
	{
		result[i] = str2[j];
		j++;
		i++;
	}
	result[i] = '\0';

	return (result);
}

/**
 * handle_path - check for executable in path variable
 * @cmd: command
 * Return: path or null
 */
char *handle_path(char *cmd)
{
	char **tokens, *path, *path_copy, *dir;
	int i = 0;
	struct stat buffer;

	path = _getenv("PATH");
	path_copy = _strdup(path);
	tokens = parsing(path_copy, " :\n");

	if (!tokens)
	{
		perror("parsing() failed");
		return (NULL);
	}
	while (tokens[i])
	{
		dir = path_concat(tokens[i], cmd);
		if (stat(dir, &buffer) == 0)
		{
			while (tokens[i])
			{
				free(tokens[i]);
				i++;
			}
			free(tokens);
			free(path_copy);
			return (dir);
		}
		else
		{
			free(dir);
			free(tokens[i]);
		}
		i++;
	}
	free(tokens);
	free(path_copy);
	if (stat(cmd, &buffer) == 0)
		return (cmd);

	return (0);
}
