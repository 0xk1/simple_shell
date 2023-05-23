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
#include <signal.h>

#define PROMPT "$ "
#define SHELL_NAME "hsh"

static int err_count __attribute__((unused));
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
char *string_concat(char *str1, char *str2, char ch);
char *_getenv(char *name);
int strdiff (char *str1, char *str2);

/** execution */
void execute(char **, char **);
char *handle_path(char *cmd);
void (*get_built_in(char *name))(char **);

/** built in */
void env_func(char **);
void exit_func(char **);
void setenv_func(char **);
void unset_func(char **);
void _cd(char **args);

/** helpers */
int handle_builtin(char **tokens);
void free_tokens(char **tokens);
int check_blank(char *);
int _setenv(char *name, char *value, int overwrite);
int _unset(char *name);
void handler_function (int i);
/** helpers 2*/
int _atoi(char *);
void cd_home(char *);
void set_old_pwd(char *);

/** _getline*/
char *insertstring(char **dst, char *str);
int check(char **buff, int n);
ssize_t _getline(char **line, size_t *n, FILE *fp);

void print_int(int n);
void print_error(char *shell_name, int errno, char *cmd);

/** _strtok */

char *_strtok(char *str, char *delim);
char *get_next(char *str, char *delim);
int char_in_delim(char c, char *delim);


#endif
