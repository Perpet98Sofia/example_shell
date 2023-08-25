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

/**
 * _strdup - return a copy of the string given as a parameter
 * @str: the string given
 *
 * Return: a pointer
 */
char *_strdup(char *str)
{
	int n = 0, i;
	char *buffer;

	if (str == NULL)
		return (NULL);
	while (str[n] != '\0')
	{
		n++;
	}

	buffer = (char *)malloc((n * sizeof(char)) + 1);
	if (buffer == NULL)
		return (NULL);

	for (i = 0; i < n; i++)
	{
		buffer[i] = str[i];
	}
	buffer[n] = '\0';

	return (buffer);
}

char *_strtok(char *buffer, char *delim)
{
	static char *next_token;
	int k;
	char *buf_cpy;

	if (buffer != NULL)
		next_token = buffer;

	while (*next_token)
	{
		while (*delim)
		{
			if (*next_token == *delim)
				break;
			delim++;
		}
		if (*delim == '\0')
			break;
		next_token++;
	}
	buf_cpy = buffer;
	if (buf_cpy[0] == '\0')
		return (NULL);
	while (*next_token != '\0' && strchr(delim, *next_token) == NULL)
		next_token++;
	if (*next_token != '\0')
	{
		*next_token = '\0';
		next_token++;
	}

	return (buf_cpy);
}
