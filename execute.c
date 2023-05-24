#include "shell.h"

/**
 * get_built_in - return pointer to a built in func based on its name
 * @name: name of built-in
 * Return: pointer to the matching built-in function or null
 */

void (*get_built_in(char *name))(char **, char *)
{
	int i = 0;

	built_in_t built_in[] = {
		{"exit", exit_func},
		{"env", env_func},
		{"setenv", setenv_func},
		{"unset", unset_func},
		{"cd", _cd},
		{NULL, NULL}
	};

	while (built_in[i].name)
	{
		if (_strcmp(name, built_in[i].name) == 0)
			return (built_in[i].func);
		i++;
	}

	return (NULL);
}

/**
 * handle_builtin - handle_builtin
 * @tokens: tokens
 * @input: input
 * Return: 1 or 0
 */
int handle_builtin(char **tokens, char *input)
{
	void (*func)(char **, char *);

	func = get_built_in(tokens[0]);
	if (func)
	{
		func(tokens, input);
		return (1);
	}
	return (0);
}

/**
 * execute - function that execute commands
 * @tokens: array of tokens
 * @input: input
 * @argv: argv
 */

void execute(char **tokens, char *argv[], char *input)
{
	char *cmd = tokens[0], *path;
	pid_t pid;

	if (handle_builtin(tokens, input) == 0)
	{
		path = handle_path(cmd);
		if (!path)
		{
			err_count++;
			print_error(argv[0], err_count, cmd);
			_puts(": not found\n", 2);
			return;
		}

		pid = fork();
		if (pid == 0)
		{
			if (execve(path, tokens, environ) == -1)
			{
				err_count++;

				print_error(argv[0], err_count, cmd);
				_puts(": ", 2);
				perror("");
				exit(2);
			}
		}
		else if (pid > 0)
			wait(NULL);
		else
			perror("fork() failed");

		if (path != cmd)
			free(path);
	}
}

/**
 * print_error - helper function to print errors
 * @shell_name: shell name
 * @errno: error number
 * @cmd: command
 */
void print_error(char *shell_name, int errno, char *cmd)
{
	_puts(shell_name, 2);
	_puts(": ", 2);
	print_int(errno);
	_puts(": ", 2);
	_puts(cmd, 2);
}
