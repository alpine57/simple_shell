#include"main.h"
char *prompt_read(void) {
    char *user_input = NULL;
   

    while (1) {
        if (isatty(STDIN_FILENO) && write(STDOUT_FILENO, "$ ", 2) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        user_input = fun_getline();

        if (user_input == NULL) {
            fprintf(stderr, "\n");
            return NULL;
        }

      
        while (*user_input == ' ' || *user_input == '\t' || *user_input == '\n') {
            user_input++;
        }

        if (*user_input == '\0') {
            free(user_input);
            continue;
        }

        break;
    }

    return user_input;
}

