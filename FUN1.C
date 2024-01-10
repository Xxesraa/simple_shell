#include "shell.h"

/**
 * display_pro - display prompt
 * Return: nothing
*/
void display_pro(void)
{
	printf("#cisfun$ ");
}
/**
 * execute_com - execute command
 * @a: args
 * Return: nothing
*/
void execute_com(char **a)
{
	pid_t cpid;
	int s;

	cpid = fork();

	if (cpid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (cpid == 0)
	{
		if (execvp(a[0], a) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(cpid, &s, 0);
	}
}
/**
 * parse_inp - parse input
 * @i: input
 * @a: args
*/
void parse_inp(char *i, char **a)
{
	int j = 0;
	char *token = strtok(i, " ");

	while (token != NULL)
	{
		a[j++] = token;
		token = strtok(NULL, " ");
	}

	a[j] = NULL;
}

