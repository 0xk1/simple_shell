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

/**
 * cd_home - handle the cd wihout arguments case
 * @buff: buffer
 */

void cd_home(char *buff)
{
	int check = 0;

	check = chdir("/root");

	if (!check)
	{
		_setenv("OLDPWD", _getenv("PWD"), 0);
		if (getcwd(buff, sizeof(buff)) != NULL)
			_setenv("PWD", buff, 0);
	}
}
/**
 * set_old_pwd - set the OLDPWD variable if not exists
 * @buff: buffer
 */

void set_old_pwd(char *buff)
{
	char *temp;

	temp = _getenv("PWD");
	chdir("..");
	if (getcwd(buff, sizeof(buff)) != NULL)
		_setenv("OLDPWD", buff, 0);
	else
		perror("getcwd");
	chdir(temp);
}

char *strenv(char *env, char *variable, char *value)
{
	int j = 0, i = 0, len_var, len_value;

	if (!variable)
		return (0);

	len_value = _strlen(value);
	len_var = _strlen(variable);
	while (i < len_var)
	{
		env[i] = variable[i];
		i++;
	}
	env[i] = '=';
	i++;
	while (j < len_value)
	{
		env[i] = value[j];
		j++;
		i++;
	}
	env[i] = '\0';

	return (env);
}