#include "shell.h"

/**
 * display_p - display play
 * Return: nothing
*/
void display_p(void)
{
	printf(":) ");
}
/**
 * execute_c - execute command
 * @a: args
 * Retrun: nothing
*/
void execute_c(char **a)
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
 * parse_i - parse input
 * @i: input
 * @a: args
 * Return: nothing
*/
void parse_i(char *i, char **a)
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
 * main - entry point
 * Return:0
*/
int main(void)
{
	char i[MAX_INPUT];
	char *a[MAX_ARGS];

	while (1)
	{
		display_p();

		if (fgets(i, sizeof(i), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		i[strcspn(i, "\n")] = '\0';

		if (strlen(i) > 0)
		{
			parse_i(i, a);

			if (strcmp(a[0], "exit") == 0)
			{
				exit(0);
			}
			if (access(a[0], X_OK) != -1)
			{
				execute_c(a);
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

