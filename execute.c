#include "shell.h"


void (*get_built_in(char *name))(char **)
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

int handle_builtin(char **tokens)
{
	void (*func)(char **);

	func = get_built_in(tokens[0]);
	if (func)
	{
		func(tokens);
		/**
 		if (_strcmp(tokens[0], "exit") == 0)
				exit(0);*/
		return (1);
	}
	return (0);
}

/**
 * execute - function that execute commands
 * @tokens: array of tokens
 */

void execute(char **tokens, char *argv[])
{
	char *cmd = tokens[0], *path;
	pid_t pid;

	if (handle_builtin(tokens) == 0)
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
				exit(EXIT_FAILURE);
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

void print_error(char *shell_name, int errno, char *cmd)
{
	_puts(shell_name, 2);
	_puts(": ", 2);
	print_int(errno);
	_puts(": ", 2);
	_puts(cmd, 2);
}
