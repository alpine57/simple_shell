#include "main.h"

char *prompt_read(void) {
    char *user_input = NULL;

    while (1) {
        if (isatty(STDIN_FILENO) && write(STDOUT_FILENO, "$ ", 2) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        user_input = fun_getline();

        if (user_input == NULL) {
            if (isatty(STDIN_FILENO)) {
                fprintf(stderr, "\n");
                exit(EXIT_SUCCESS);
            } else {
                fprintf(stderr, "Error Unable to read input.\n");
                continue;
            }
        }

        break;
    }

    return user_input;
}

