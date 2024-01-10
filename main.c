#include "shell.h"
int main(void)
{
	char i[MAX_INPUT];
	char *a[MAX_ARGS];
	{
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
	}
	{
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
	}

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
	{
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
	}
	return (0);
}
