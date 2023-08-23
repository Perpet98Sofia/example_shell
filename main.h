#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>


#define UNUSED(x) (void)(x)
#define MAX_LINE_LENGTH 1024
#define PROMPT "(simple-shell)~#\n$ "

/* Functions for printing */
int print_string(const char *format);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *str);

/* Functions for handling commands */
void split_line(char *line, char **argv);

/* Main function: For executing commands */
void execute(char **argv, char *env[]);

int _cd(char **str, list_t *env, int num)
int cd_execute(list_t *env, char *current, char *dir, char *str, int num)
void cd_only(list_t *env, char *current)
int c_setenv(list_t **env, char *name, char *dir)
char *c_strcat(char *dest, char *src)

#endif
