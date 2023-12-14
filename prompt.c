#include "main.h"
#include <unistd.h>

char *prompt_read(void) {
    char *user_input = NULL;

    while (1) {
        if (isatty(STDIN_FILENO) && write(STDOUT_FILENO, "$ ", 2) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        
    user_input = getline();
    if (user_input == NULL) {
        if (isatty(STDIN_FILENO)) {
            write(STDOUT_FILENO, "\n", 1);
            exit(EXIT_SUCCESS);
        } else {
            exit(EXIT_SUCCESS);
        }
    }

    *fd_check = s_len(user_input);

    if (*fd_check == -1) {
        if (isatty(STDIN_FILENO)) {
            write(STDOUT_FILENO, "\n", 1);
            free(user_input);
            exit(EXIT_SUCCESS);
        } else {
            free(user_input);
            exit(EXIT_SUCCESS);
        }
    }

    if (*fd_check == 0 && isatty(STDIN_FILENO)) {
        free(user_input);
        return prompt_read(fd_check);
    }

    user_input[_strcspn(user_input, "\n")] = '\0';
    return user_input;
}
