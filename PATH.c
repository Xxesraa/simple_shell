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

