#include "shell.h"

static char *next;

/**
 * char_in_delim - check if character present in a delimiter string
 * @c: character
 * @delim: delimiter
 * Return: 1 or 0
 */
int char_in_delim(char c, char *delim)
{
	int i = 0;

	while (delim[i])
	{
		if (c == delim[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * get_next - get the next token
 * @str: string
 * @delim: delimiter
 * Return: pointer to next token or null
 */
char *get_next(char *str, char *delim)
{
	int i = 0;

	while (str[i])
	{
		if (char_in_delim(str[i], delim))
		{
			str[i] = '\0';
			while (char_in_delim(str[i + 1], delim))
			{
				str[i + 1] = '\0';
				i++;
			}

			if (str[i + 1] != '\0')
				return (&str[i + 1]);
			return (NULL);
		}
		i++;
	}

	return (NULL);
}
/**
 * _strtok - function that tokonizes a string
 * @str: string
 * @delim: delimiter
 * Return: pointer to the current token or null
 */
char *_strtok(char *str, char *delim)
{

	if (!str)
	{
		str = next;
		if (!str)
			return (NULL);
	}

	while (*str && *str == ' ')
		str++;

	next = get_next(str, delim);

	return (str);
}

