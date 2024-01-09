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
	extern char **e;
	char **env = e;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
/**
 * main - entry point
 * Return: 0
*/
int main(void)
{
	char i[MAX_INPUT];
	char *a[MAX_ARGS];

	while (1)
	{
		display_pr();

		if (fgets(i, sizeof(i), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		i[strcspn(i, "\n")] = '\0';

		if (strlen(i) > 0)
		{
			parse_in(i, a);
			if (strcmp(a[0], "exit") == 0)
			{
				exit(0);
			}
			else if (strcmp(a[0], "env") == 0)
			{
				display_e();
			}
			else
			{
				if (access(a[0], X_OK) != -1)
				{
					execute_co(a);
				}
				else
				{
					fprintf(stderr, "Command not found: %s\n", a[0]);
				}
			}
		}
	}
	printf("\n");
	return (0);
}
