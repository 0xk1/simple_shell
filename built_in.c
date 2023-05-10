#include "shell.h"


void exit_func(char **args)
{
	int i = 0;
	
	while (args[i])
		i++;
	if (i == 1)
	{
		while (args[i])
			free(args[i]);
		free(args);
		exit(EXIT_SUCCESS);
	}
	else
	{
		_puts("to much arguments for exit command\n");
		return;
	}

}

void env_func(char **args __attribute__((unused)))
{
	int i = 0;

	while (environ[i])
	{
		_puts(environ[i]);
		_puts("\n");
		i++;
	}

}
