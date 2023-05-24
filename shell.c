#include "shell.h"
/**
 * main - Entry point
 * Return: 0
 * @argc: argc
 * @argv: argv
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	char **tokens, *input = NULL;
	size_t n = 0;
	ssize_t n_chars;
	bool run = true;
	int status = 0;

	while (run)
	{
		if (isatty(STDIN_FILENO))
			_puts(PROMPT, 1);
		else
			run = false;
		signal(SIGINT, handler_function);
		n_chars = getline(&input, &n, stdin);

		if (n_chars == EOF)
		{
			_puts("\nExiting...\n", 1);
			free(input);
			exit(status);
		}
		if ((n_chars == 1 && input[0] == '\n') || check_blank(input) == 0)
			continue;
		tokens = parsing(input, " \t\"\'\n");
		if (!tokens)
		{
			perror("parsing failed");
			return (2);
		}
		execute(tokens, argv, input, &status);
		free_tokens(tokens);
		if (input)
		{
			free(input);
			input = NULL;
		}
		n = 0;
	}
	free(input);
	return (status);
}

