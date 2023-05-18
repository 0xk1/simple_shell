#include "shell.h"

static int err_count;

int pritsu(int i)
{
	i++;
	_puts(": \"", 2);
	_putchar(59, 2);
	_puts("\" unexpected\n", 2);
	return (i);
}

int isSpaceString(const char *str) {
	while (*str) {
		if (*str != ' ')
			return (1);
		str++;
	}
	return (0);
}

int help_excute(char *input, char *argv[])
{
	char **cmdtok, **tokens;
	int i = 0, test = 0;

	cmdtok = parsing(input, ";\n");/*first tookinzing of imput by ;*/
	if (cmdtok == NULL)
	{
		perror("malloc() failed");
		return (0);
	}
	while (cmdtok[i] != NULL)
	{
		if (isSpaceString(cmdtok[i]) == 0 || _strcmp(cmdtok[0], "\t\t\t") == 0)
		{
			err_count++;
			if (_strcmp(cmdtok[0], "\t\t\t") != 0)
			{
				print_error(argv[0], err_count, "Syntax error");
				pritsu(i);
			}
			test = 1;
			break;
		}
		i++;
	}
	i = 0;
	if (test == 0) /* only excute if theres is no blank command*/
	{
		while (cmdtok[i] != NULL)
		{
			tokens = parsing(cmdtok[i], " \t\n");
			if (!tokens)
			{
				perror("parsing failed");
				return (0);
			}
			execute(tokens, argv, &err_count);
			free_tokens(tokens);
			i++;
		}
	}
	free_tokens(cmdtok);
	return (1);
}
