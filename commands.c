#include "main.h"

void execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
      
    } else {
        do {
            pid_t wpid = waitpid(pid, &status, WUNTRACED);
            if (wpid == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void cd_command(char **args) {
    char *new_directory;
    char *current_directory;
    int chdir_status, setenv_status;

    if (args[1] == NULL) {
        new_directory = getenv("HOME");
    } else if (strcmp(args[1], "-") == 0) {
        new_directory = getenv("OLDPWD");
    } else {
        new_directory = args[1];
    }

    current_directory = getcwd(NULL, 0);

    if (current_directory == NULL) {
        perror("Error");
        return;
    }

    chdir_status = chdir(new_directory);

    if (chdir_status != 0) {
        perror("Error");
        free(current_directory);
        return;
    }

    setenv_status = setenv("OLDPWD", current_directory, 1);

    if (setenv_status != 0) {
        perror("Error");
    }

    setenv_status = setenv("PWD", new_directory, 1);

    if (setenv_status != 0) {
        perror("Error");
    }

    free(current_directory);
}

