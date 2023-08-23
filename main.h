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

/* Functions for handling commands */
void split_line(char *line, char **argv);
char *find_cmd(const char *buffer);
char *find_executable(const char *command, char **envp);
char *make_cmd(char *entry, char *exec);
char *removeSpaces(const char *strng);
char *trim(char *str);
void free_all(char *strng, char *strg, int status);
void handle_command(char *entry, char **envp, char **argv);
void command_not_found_error(const char *command);
void print_string_stderr(const char *str);
int is_space(char c);
int is_digit(char c);

/* Built_in functions */
void builtin_exit(char *entry);
void builtin_env(char *env[]);

/* Main function: For executing commands */
void execute(char **argv, char *env[]);

#endif
