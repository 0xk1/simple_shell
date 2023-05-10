#include "shell.h"

/**
 * main - Entry point
 * Return: 0
 */
int main(void)
{
	char *input = NULL, **tokens;
	size_t n = 0;
	ssize_t n_chars;
	int j;
	bool run = true;

	while (run)
	{
		if (isatty(STDIN_FILENO))
			_puts(PROMPT);
		else
			run = false;

		n_chars = getline(&input, &n, stdin);

		if (n_chars == EOF)
		{
			_puts("\nExiting...\n");
			free(input);
			exit(EXIT_SUCCESS);
		}

		if (n_chars == 1 && input[0] == '\n')
			continue;
		tokens = parsing(input , " \n");

		if (!tokens)
		{
			perror("parsing failed");
			return (0);
		}
		execute(tokens);

		for (j = 0; tokens[j] != NULL; j++)
			free(tokens[j]);

		free(tokens);
		free(input);
		input = NULL;
		n = 0;
	}
	free(input);
	return (0);
}
