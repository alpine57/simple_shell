#include "main.h"
void tokenize(char *input, char ***args) {
    size_t arg_count = 0;
    char *token = strtok(input, " \t\n");
    char **temp;

    *args = malloc(sizeof(char*) * 2);

    if (*args == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    while (token) {
        (*args)[arg_count] = strdup(token);

        if ((*args)[arg_count] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }

        arg_count++;

        temp = realloc(*args, sizeof(char*) * (arg_count + 2));
        if (temp == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }

        *args = temp;
        (*args)[arg_count] = NULL;

        token = strtok(NULL, " \t\n");
    }
}

