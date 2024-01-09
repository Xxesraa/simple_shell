#include "shell.h"
/**
 * display_prom - display prompt
 * Return: nothing
*/
void display_prom(void)
{
	printf(":) ");
}
/**
 * execute_comm - execute command
 * @a: args
 * Return: nothing
*/
void execute_comm(char **a)
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
 * parse_inpu - parse input
 * @i: input
 * @a: args
 * Return: nothing
*/
void parse_inpu(char *i, char **a)
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
 * main - Entry point
 * Return: 0
*/
int main(void)
{
	char i[MAX_INPUT];
	char *a[MAX_ARGS];

	while (1)
	{
		display_prom();

		if (fgets(i, sizeof(i), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		i[strcspn(i, "\n")] = '\0';

		if (strlen(i) > 0)
		{
			parse_inpu(i, a);

			if (access(a[0], X_OK) != -1)
			{
				execute_comm(a);
			}
			else
			{
				fprintf(stderr, "Command not found: %s\n", a[0]);
			}
		}
	}

	printf("\n");

	return (0);
}

