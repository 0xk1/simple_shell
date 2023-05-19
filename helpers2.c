#include "shell.h"

/**
 * _atoi - converts string to an integer
 * @nptr: string to be converted
 * Return: converted integer value or -1
 */

int _atoi(char *nptr)
{
	int i = 0, n = 0;

	if (nptr[i] == '+')
		i++;

	while (nptr[i])
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			return (-1);

		n = (n * 10) + (nptr[i] - '0');
		i++;
	}

	return (n);
}

