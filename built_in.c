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
	_puts("sssss", 1);
	return;
}