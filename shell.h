#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64
extern char **environ;

/*FUN1.C*/
void display_pro(void);
void execute_com(char **a);
void parse_inp(char *i, char **a);

/*FUN2.c*/
void display_prom(void);
void execute_comm(char **a);
void parse_inpu(char *i, char **a);

/*exit.c*/
void display_p(void);
void execute_c(char **a);
void parse_i(char *i, char **a);


/*env.c*/
void display_pr(void);
void execute_co(char **a);
void parse_in(char *i, char **a);
void display_e(void);

/*PATH.c*/

void execute_comma(char *c);
void d_prompt(void);

/*fun.c*/
int _strcmp(char *s1, char *s2);
int _strlen(char *s);



#endif
