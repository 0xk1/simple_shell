#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>

#define PROMPT "$ "

extern char **environ;


typedef struct built_in
{
	char *name;
	void (*func)(char **);
} built_in_t;

/** parsing */
char **parsing(char *input, char *delimiter);

/** strings */
int _putchar(char c, int buffer);
void _puts(char *s, int buffer);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strcmp(const char *s1, const char *s2);
char *path_concat(char *str1, char *str2);

char *_getenv(char *name);

/** execution */

void execute(char **, char **);
char *handle_path(char *cmd);

void (*get_built_in(char *name))(char **);

/** built in */
void env_func(char **);
void exit_func(char **);

/** helpers */

void handle_builtin(char **tokens);
void free_tokens(char **tokens);
int check_blank(char *);
void print_int(int n);
void print_error(char *shell_name, int errno, char *cmd);
#endif
