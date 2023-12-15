#include "main.h"
/**
 * env_command - print current environment variables
 * @args: arguments (including command itself)
 */
void handle_env_command(char **args) {
    extern char **environ;
    char **env = environ;
    int flag_i = 0;

    if (args[2] != NULL || (args[1] && strcmp(args[1], "-i") != 0)) {
        fprintf(stderr, "Error: Too many arguments for env command\n");
        return;
    }

    if (args[1] && strcmp(args[1], "-i") == 0) {
        env = malloc(sizeof(char*));
        if (env == NULL) {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }
        env[0] = NULL;
        flag_i = 1;
    }

    while (*env != NULL) {
        printf("%s\n", *env);
        env++;
    }

    if (flag_i) {
        free(env);
    }
}
void handle_setenv_command(char **args) {
    if (args[1] == NULL || args[2] == NULL || args[3] != NULL) {
        fprintf(stderr, "Usage: setenv variable value\n");
        return;
    }

    if (setenv(args[1], args[2], 1) != 0) {
        perror("setenv");
    }
}

void handle_unsetenv_command(char **args) {
    if (args[1] == NULL || args[2] != NULL) {
        fprintf(stderr, "Usage: unsetenv variable\n");
        return;
    }

    if (unsetenv(args[1]) != 0) {
        perror("unsetenv");
    }
}

