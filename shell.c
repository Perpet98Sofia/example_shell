#include "main.h"

/**
 * execute - Executes a command
 *
 * @argv: command line arguments
 * @env: a NULL terminated list of strings
 *
 * Return: void
*/
void execute(char **argv, char *env[])
{
	int pid = 0, i = 0, status;
	char *envp[MAX_LINE_LENGTH];

	if (_strncmp(argv[0], "/usr/bin/cd", 11) == 0)
	{
		if (argv[1])
			chdir(argv[1]);
		chdir("/");
		return;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (env)
		{
			for (i = 0; env[i]; i++)
				envp[i] = strdup(env[i]);
		}
		envp[i] = NULL;
		env = envp;
		if (execve(argv[0], argv, envp) == -1)
		{
			print_string("shell: error: ");
			print_string(argv[0]);
			print_string("\n");
			exit(EXIT_FAILURE);
		}
	}
	else
		waitpid(pid, &status, 0);
}
