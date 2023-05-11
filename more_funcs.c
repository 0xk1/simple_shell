#include "shell.h"

/**
 * _strncmp - compares first n bytes of s1 and s2
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes to compare
 * Return: int
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	while (s1[i] && (i < n))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}

	return (0);
}

/**
 * _strcmp - compare two strings
 * @s1: string 1
 * @s2: string 2
 * Return: int
 */

int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}

	return (0);
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
		if (inmput[i] == ' ')
			i++;
		else
			return (1);
	}
	return (0);
}
