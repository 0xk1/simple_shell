#include "shell.h"

/**
 * _putchar - print char
 * @c: char to print
 * @buffer: buffer
 * Return: 1 or -1
 */
int _putchar(char c, int buffer)
{
	return (write(buffer, &c, 1));
}

/**
 * _puts - prints a string
 * @s: string
 * @buffer: buffer
 */
void _puts(char *s, int buffer)
{

	write(buffer, s, _strlen(s));
}

/**
 * _strlen - function that returns the len of string
 * @s: string
 * Return: len
 */

int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (s[i])
		i++;

	return (i);
}

/**
 * _strcpy - copy src to dets
 * @dest: dest
 * @src: src
 * Return: dest
 */

char *_strcpy(char *dest, char *src)
{
	int len, i = 0;

	if (!dest)
		return (0);

	len = _strlen(src);

	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * _strdup - duplicate a string
 * @s: string to duplicate
 * Return: pointer to new string
 */
char *_strdup(char *s)
{
	char *copy = NULL;
	int len;

	if (!s)
		return (NULL);

	len = _strlen(s);

	copy = malloc(sizeof(char) * len + 1);

	if (!copy)
	{
		perror("malloc() failed");
		return (NULL);
	}

	_strcpy(copy, s);

	/*s[len] = '\0';*/
	return (copy);
}
