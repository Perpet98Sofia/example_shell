#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>

typedef struct list
{
    char *var;
    char *value;
    list_t *next;
} list_t;

typedef struct alias_struct
{
    char *name;
    char *value;
    alias_t *next;
} alias_t;

#define UNUSED(x) (void)(x)
#define MAX_LINE_LENGTH 1024
#define PROMPT "(simple-shell)~#\n$ "

/* Functions for handling char */
int print_string(const char *format);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *str);
char *c_strdup(char *str, int cs);
char *c_strcat(char *dest, char *src);
void split_line(char *line, char **argv);
/* -- getline function -- */
void assign_lineptr(char **lineptr, size_t *n,
                    char *buffer, size_t b);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/* Functions for handling commands */
char *_which(char *str, list_t *env);
char *get_args(char *line, int *exe_ret);
int call_args(char **args, char **front, int *exe_ret);
int run_args(char **args, char **front, int *exe_ret);
int handle_args(int *exe_ret);
int check_args(char **args);
/* -- cd command -- */
void cd_only(list_t *env, char *current);
int cd_execute(list_t *env, char *current, char *dir,
                char *str, int num);
int _cd(char **str, list_t *env, int num);
/* -- alias command -- */
int shellby_alias(char **args,
                char __attribute__((__unused__)) **front);
void set_alias(char *var_name, char *value);
void print_alias(alias_t *alias);
char **replace_aliases(char **args);

/* -- alias command -- */
int shellby_alias(char **args,
                char __attribute__((__unused__)) **front);
void set_alias(char *var_name, char *value);
void print_alias(alias_t *alias);
char **replace_aliases(char **args);

/* Functions for env built-in */
int find_env(list_t *env, char *str);
char *get_env(char *str, list_t *env);
int _unsetenv(list_t **env, char **str);
int _setenv(list_t **env, char **str);

/* Functions memory handling */
void *_realloc(void *ptr, unsigned int old_size,
                unsigned int new_size);

/* Main function: For executing commands */
void execute(char **argv, char *env[]);

#endif
