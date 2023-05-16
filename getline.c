#include "shell.h"

/*
*Important notice : the buffer used for _getline argument
*must be initialized to NULL or allocated, otherwise it will give an error
*/

/**
 * insertstring - concat dst and str
 * @dst: destination
 * @str: string to add
 * Return: allocated memory to new dst
*/

char *insertstring(char **dst, char *str)
{
	if (*dst == NULL && str == NULL)
		return (NULL);
	if (*dst == NULL)
	{
		int i = 0;
		*dst = malloc(_strlen(str));
		while (str[i] != 0)
		{
			(*dst)[i] = str[i];
			i++;
		}
		return (*dst);
	}
	else
	{
		int i = 0, j = 0;
		int ln, lif;
		char *dstcopy = *dst;

		ln = _strlen(*dst);
		lif = _strlen(str);
		*dst = malloc(ln + lif - 1);

		while (j < ln)
		{
			(*dst)[j] = dstcopy[j];
			j++;
		}
		while (i <= lif)
		{
			(*dst)[ln + i] = str[i];
			i++;
		}
			free(dstcopy);

		return (*dst);
	}
}

/**
 * check - check if buff contain \n
 * @buff: the string
 * @n: number of characters read in (read)
 * Return: 0 if it doesnt 1 if it does
*/
int check (char **buff, int n)
{
	int i = 0, j = 0;
	int kn = 0;
	char *new, *copybuff;

	while ((*buff)[i] != '\0')
	{
		if ((*buff)[i] == '\n')
		{
			kn = 1;
			break;
		}	
		i++;
	}
	if (kn == 1)
	{
		new = malloc(i + 2);
		copybuff = *buff;
		if (i != 0)
		{
			while (j <= i)
			{
				new[j] = copybuff[j];
				j++;
			}
		}
		else
			new[i] = '\n';
		new[i + 1] = '\0';
		*buff = new;
		free(copybuff);
	}
	if (kn == 0 && n < 1024)
		{
			kn = 1;
		}
	return (kn);
}


/**
 * _getline - prototype of getline
 * @line: the buffer to store the new line
 * @n: the number of char read
 * @fp: FILE structur
 * Return: the number of charcters read
*/
ssize_t _getline(char **line, size_t *n, FILE *fp)
{
	char *buff, *copyline;
	int i, rd;
	int fd = fp->_fileno;

	copyline = malloc(1024);
	rd = read(fd, copyline, 1023);
	if (rd == -1)
		return (-1);
	if (rd == 0)
		return (EOF);
	copyline[rd] = '\0';
	i = check(&copyline, rd);
	while (i == 0)
	{
		buff = malloc(1024);
		rd = read(fd, buff, 1023);
		buff[rd] = 0;
		copyline = insertstring(&copyline, buff);
		i = check(&copyline, rd);
		free(buff);
	}
	*line = copyline;
	*n = _strlen(*line);
	return (*n);
}
