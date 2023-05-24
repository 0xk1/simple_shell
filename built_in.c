#include "shell.h"

/**
 * exit_func - built in exit
 * @args: tokens
 * @input: input
 */
int exit_func(char **args, char *input)
{
	int i = 0;

	while (args[i])
		i++;
	if (i == 1)
	{
		free_tokens(args);
		free(input);
		exit(0);
	}
	if (_atoi(args[1]) == -1)
	{
		_puts(SHELL_NAME, 2);
		_puts(": ", 2);
		print_int(err_count);
		_puts(": exit: Illegal number: ", 2);
		_puts(args[1], 2);
		_puts("\n", 2);
		return (0);
	}
	exit(_atoi(args[1]));
}

/**
 * env_func - built in env
 * @args: tokens
 * @input: input
 */

int env_func(char **args, char *input)
{
	int i = 0;

	(void)input;

	while (args[i])
		i++;
	if (i > 1)
	{
		_puts("env: '", 2);
		_puts(args[1], 2);
		_puts("': No such file or directory\n", 2);
		return (0);
	}

	while (environ[i])
	{
		_puts(environ[i], 1);
		_puts("\n", 1);
		i++;
	}
	return (0);

}

/**
 * setenv_func - built-in setenv
 * @args: tokens
 * @input: input
 */
int setenv_func(char **args, char *input)
{
	int i = 0;

	(void)input;

	while (args[i])
		i++;
	if (i == 3)
		_setenv(args[1], args[2], 0);
	return (0);
}

/**
 * unset_func - built-in unsetenv
 * @args: tokens
 * @input: input
 */

int unset_func(char **args, char *input)
{
	int i = 0;

	(void)input;

	while (args[i])
		i++;
	if (i == 2)
		_unset(args[1]);
	return (0);
}

/**
 * _cd - built-in cd
 * @args: tokens
 * @input: input
 */
int _cd(char **args, char *input __attribute__((unused)))
{
	int i = 0, check = 0;
	char buff[1024];

	while (args[i])
		i++;

	if (!_getenv("OLDPWD"))
		set_old_pwd(buff);

	if (i == 1)
	{
		cd_home(buff);
		return (0);
	}
	if (i == 2)
	{
		if (_strcmp(args[1], "-") == 0)
			check = chdir(_getenv("OLDPWD"));
		else
			check = chdir(args[1]);

		if (!check)
		{

			_setenv("OLDPWD", _getenv("PWD"), 0);
			if (getcwd(buff, sizeof(buff)) != NULL)
			{
				if (strcmp(args[1], "-") == 0)
				{
					_puts(buff, 2);
					_puts("\n", 2);
				}
				_setenv("PWD", buff, 0);
				return (0);
			}
		}
	}
	_puts("hsh: 1: cd: can't cd to ", 2);
	_puts(args[1], 2);
	_puts("\n", 2);
	return (0);
}

