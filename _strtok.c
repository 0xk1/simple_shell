#include "shell.h"

static char *next = NULL;

char *get_next(char *str, char *delim)
{
	int i = 0, j;

	while (str[i])
	{
		j = 0;
		while (delim[j])
		{
			if (str[i] == delim[j])
			{
				str[i] = '\0';

				if (str[i + 1] != '\0')
					return (&str[i + 1]);

				return (NULL);
			}
			j++;
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

