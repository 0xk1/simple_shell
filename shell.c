#include "shell.h"
char *input;
/**
 * main - Entry point
 * Return: 0
 */
int main(void)
{
	char **tokens;
	size_t n = 0;
	ssize_t n_chars;
	bool run = true;

	while (run)
	{
		if (isatty(STDIN_FILENO))
			_puts(PROMPT, 1);
		else
			run = false;

		n_chars = _getline(&input, &n, stdin);
		
		if (n_chars == EOF)
		{
			_puts("\nExiting...\n", 1);
			free(input);
			exit(EXIT_SUCCESS);
		}

		if ((n_chars == 1 && input[0] == '\n') || check_blank(input) == 0)
			continue;

		tokens = parsing(input, " \t\n");

		if (!tokens)
		{
			perror("parsing failed");
			return (0);
		}
		execute(tokens);

		free_tokens(tokens);
		free(input);
		input = NULL;
		n = 0;
	}
	free(input);
	return (0);
}
