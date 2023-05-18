#include "shell.h"

/**
 * main - Entry point
 * @argc : number of args
 * @argv : args
 * Return: 0
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	size_t n = 0;
	ssize_t n_chars;
	bool run = true;
	char *input;

	while (run)
	{
		if (isatty(STDIN_FILENO))
			_puts(PROMPT, 1);
		else
		{
			run = false;
		}
		signal(SIGINT, handler_function);
		n_chars = _getline(&input, &n, stdin);

		if (n_chars == EOF)
		{
			_puts("\nExiting...\n", 1);
			free(input);
			exit(EXIT_SUCCESS);
		}

		help_excute(input, argv);
		free(input);
		input = NULL;
		n = 0;
	}
	free(input);
	return (0);
}
