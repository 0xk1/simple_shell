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
	char **ar_cmds;
	int i = 0;

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
			exit(EXIT_SUCCESS);
		}
		if ((n_chars == 1 && input[0] == '\n') || check_blank(input) == 0)
			continue;

		ar_cmds = parsing(input, "\n");
		while (ar_cmds[i] != NULL)
		{
			tokens = parsing(ar_cmds[i], " \t\n\"\'");
			if (!tokens)
			{
				perror("parsing failed");
				return (0);
			}
			execute(tokens, argv, input);
			free_tokens(tokens);
			i++;
		
			if (input)
			{
				free(input);
				input = NULL;
			}
			
			free_tokens(ar_cmds);
			ar_cmds = NULL;
			n = 0;
		}
	}
	free(input);
	return (0);
}
