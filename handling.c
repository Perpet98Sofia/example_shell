#include "main.h"

/**
 * split_line - split a line into strings separated
 *
 * @line: the line to split
 * @argv: the variable where the strings will be stored
 *
 * Return: void
*/
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

/**
 * _strncmp - compares two strings of n characters
 * @s1: char*
 * @s2: char*
 * @n: number
 * Return: 0 (s1 == s2 || c == n) -1 otherwise
 */
int _strncmp(char *s1, char *s2, int n)
{
	int c = 0;

	while (((s1[c] != '\0') && (s2[c] != '\0')) && s1[c] == s2[c])
	{
		c++;
	}

	if (c == n)
		return (0);
	else if (s1[c] == s2[c])
		return (0);
	else
		return (-1);
}
