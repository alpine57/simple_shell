#ifndef MAIN_H
#define MAIN_H
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#include <sys/wait.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h> 
 
#define BUFFER_SIZE 1024
#define MAX_ARG_SIZE 64

char *prompt_read(void);
char *fun_getline(void);
void exit_shell(char **receive_argv, int execution_status);
 #endif
