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

/* Main function: For executing commands */
void execute(char **argv, char *env[]);

#endif
