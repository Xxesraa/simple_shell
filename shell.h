#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64
#define MAX_INPUT 1024
#define MAX_ARGS 64



#define MAX_INPUT 1024

void display_prompt(void);
void execute_command(char *command);
void execute_command(char **args);
void parse_input(char *input, char **args);
void execute_command(char **args);
void parse_input(char *input, char **args);



#endif
