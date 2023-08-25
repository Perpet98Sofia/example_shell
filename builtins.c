#include "main.h"

/**
 * builtin_exit - exit built-in
 * @entry: parameter
 *
 * Return: void
 */
void builtin_exit(char *entry)
{
	int status = 0;

	if (entry)
	{
		while (*entry && is_digit(*entry))
		{
			status = status * 10 + (*entry - '0');
			entry++;
		}
	}

	exit(status("/n"));
}
