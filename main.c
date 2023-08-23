#include "main.h"

/**
 * main - Entry point
 *
 * @ac: Arguments count
 * @av: a NULL terminated list of strings
 * @env: a NULL terminated list of strings that point to the
 * current environment
 *
 * Return: Always 0
*/
int main(int ac, char **av, char *env[])
{
	char *entry, *envp[MAX_LINE_LENGTH], *argv[MAX_LINE_LENGTH];
	size_t size = 0;
	int i = 0, is_interact = (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO)
								&& ac == 1);

	UNUSED(av);
	while (1)
	{
		entry = malloc(MAX_LINE_LENGTH + 1);
		if (entry == NULL)
			return (-1);

		if (is_interact)
			print_string(PROMPT);
		if (getline(&entry, &size, stdin) == -1)
		{
			if (feof(stdin))
			{
                free(entry);
                exit(0);
            }
			else
			{
                free(entry);
                exit(EXIT_FAILURE);
            }
		}
		split_line(entry, argv);  /* *argv = { entry, NULL} */
		if (env)
		{
			for (i = 0; env[i]; i++)
				envp[i] = strdup(env[i]);
		}
		envp[i] = NULL;
        if (access(entry, X_OK) == 0)
		    execute(argv, envp);
        else
            print_string("./shell: No such file or directory\n");
        free(entry);
	}
	return (0);
}
