#include "shell.h"

/**
 * display_pr - display print
 * Return: nothing
*/
void display_pr(void)
{
	printf("$ ");
}
/**
 * execute_co - execute commond
 * @a: args
 * Return: nothing
*/
void execute_co(char **a)
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
 * parse_in - parse input
 * @i: input
 * @a: args
 * Return: nothing
*/
void parse_in(char *i, char **a)
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
/**
 * display_e - display envsion
 * Return: nothing
*/
void display_e(void)
{
	extern char **environ;
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
