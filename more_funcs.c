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

	while ((s1[i] || s2[i]) && i < n)
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
 * print_int - function that print a number
 * @n: number to write
 * Return: number of bytes written
 */

void print_int(int n)
{
	
	if (n >= 0 && n <= 9)
		_putchar(n + '0', 2);
	else
	{
		print_int(n / 10);
		print_int(n % 10);
	}
}
