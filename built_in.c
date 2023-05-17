#include "shell.h"

/**
 * exit_func - built in exit
 * @args: tokens
 */
void exit_func(char **args)
{
	int i = 0;
	
	while (args[i])
		i++;
	if (i == 1)
	{
		free_tokens(args);
		exit(0);
	}
	else
	{
		_puts("to much arguments for exit command\n", 2);
		return;
	}

}

/**
 * env_func - built in env
 * @args: tokens
 */

void env_func(char **args)
{
	int i = 0;
	
	while (args[i])
		i++;
	if (i > 1)
		return;

	while (environ[i])
	{
		_puts(environ[i], 1);
		_puts("\n", 1);
		i++;
	}

}


void setenv_func(char **args)
{
	int i = 0;
	while (args[i])
		i++;
	if (i == 3)
		_setenv(args[1], args[2], 0);
	return;
}

void unset_func(char **args)
{
	int i = 0;
	while (args[i])
		i++;
	if (i == 2)
		_unset(args[1]);
	return;
}

void _cd(char **args)
{
	int i = 0, check = 0;
	while (args[i])
		i++;
	if (i == 2)
		check = chdir(args[1]);
	if (check == 0)
		return;
	else 
		_puts("error", 2);
}