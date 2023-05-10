#include "shell.h"

void (*get_built_in(char *name))(char **)
{
	int i = 0;

	built_in_t built_in[] = {
		{"exit", exit_func},
		{"env", env_func},
		{NULL, NULL}
	};

	while (built_in[i].name)
	{
		if (_strcmp(built_in[i].name, name) == 0)
			return (built_in[i].func);
		i++;
	}

	return (NULL);
}

/**
 * execute - function that execute commands
 * @tokens: array of tokens
 */
void execute(char **tokens)
{
	char *cmd = tokens[0], *path;
	struct stat buffer;
	pid_t pid;
	void (*p)(char **);

	p = get_built_in(cmd);

	if (p)
	{
		p(tokens);
		return;
	}

	path = handle_path(cmd);

	if (!path)
	{
		_puts("command not found\n");
		return;
	}

	pid = fork();

	if (pid == 0)
	{
		if (execve(path, tokens, environ) == -1)
		{
			if (stat(cmd, &buffer) == 0)
			{
				_puts("-bash: ");
				_puts(cmd);
				_puts(": ");
				_puts("Is a directory\n");
				exit(EXIT_FAILURE);
			}
			perror("error");
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
