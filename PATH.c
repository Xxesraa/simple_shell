#include "shell.h"

/**
 * display_prompt - display prompt
 * Return : nothing
*/

void display_prompt(void)
{
	printf("#cisfun$ ");
}

/**
 * execute_command - execute command
 * @command: command
 * Return : 0
*/
void execute_command(char *command)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (execlp(command, command, NULL) == -1)
		{
			perror("execlp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
}
/**
 * main - entry point
 * Return: 0
*/
int main(void)
{
	char input[MAX_INPUT];

	while (1)
	{
		display_prompt();

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		input[strcspn(input, "\n")] = '\0';

		if (strlen(input) > 0)
		{
			execute_command(input);
		}
	}

	printf("\n");

	return (0);
}

