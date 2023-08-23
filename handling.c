#include "main.h"

void split_line(char *line, char **argv)
{
	int i = 0;

	argv[i] = strtok(line, " \n");
	while (argv[i] != NULL)
	{
		i++;
		argv[i] = strtok(NULL, "\n");
	}
    argv[i] = NULL;
}

/**
 * print_string - Print string
 * @format: The string to print
 *
 * Return: The length of the output
 */
int print_string(const char *format)
{
	int len = 0;

	if (format == NULL)
		return (write(1, "", 1));

	while (format[len])
		len++;

	return (write(1, format, len));
}
