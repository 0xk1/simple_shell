#include "shell.h"

static char *next = NULL;

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
char *get_next(char *str, char *delim)
{
	int i = 0;

	while (str[i])
	{
		if (char_in_delim(str[i], delim))
		{
			str[i] = '\0';
			while (char_in_delim(str[i + 1],delim))
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

char *_strtok(char *str, char *delim)
{

	if (!str)
	{
		str = next;
		if (!str)
			return (NULL);
	}
	
	next = get_next(str, delim);

	return (str);
}

