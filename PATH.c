#include "shell.h"

/**
 * d_prompt - display prompt
 * Return : nothing
*/

void d_prompt(void)
{
	printf("#cisfun$ ");
}

/**
 * execute_comma - execute command
 * @c: command
 * Return : 0
*/
void execute_comma(char *c)
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
		if (execlp(c, c, NULL) == -1)
		{
			perror("execlp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(cpid, &s, 0);
	}
}
/**
 * main - entry point
 * Return: 0
*/
int main(void)
{
	char i[MAX_INPUT];

	while (1)
	{
		d_prompt();

		if (fgets(i, sizeof(i), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		i[strcspn(i, "\n")] = '\0';

		if (strlen(i) > 0)
		{
			execute_comma(i);
		}
	}

	printf("\n");

	return (0);
}

