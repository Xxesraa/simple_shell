#include "shell.h"
/**
 * display_prompt - display prompt
 * Return: nothing
*/
void display_prompt(void)
{
	printf(":) ");
}
/**
 * execute_command - execute command
 * @args: args
 * Return: nothing
*/
void execute_command(char **args)
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
		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
}
/**
 * parse_input - parse input
 * @input: input
 * @args: args
 * Return: nothing
*/
void parse_input(char *input, char **args)
{
	int i = 0;
	char *token = strtok(input, " ");

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}

	args[i] = NULL;
}
/**
 * main - Entry point
 * Return: 0
*/
int main(void)
{
	char input[MAX_INPUT];
	char *args[MAX_ARGS];

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
			parse_input(input, args);

			if (access(args[0], X_OK) != -1)
			{
				execute_command(args);
			}
			else
			{
				fprintf(stderr, "Command not found: %s\n", args[0]);
			}
		}
	}

	printf("\n");

	return (0);
}

