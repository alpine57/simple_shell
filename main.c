#include "main.h"

int main(int ac, char **argv) {
    char *user_input;
    char **receive_argv;

    (void)ac;
    (void)argv;

    while (1) {
        user_input = prompt_read();

        if (user_input == NULL) {
            printf("\n");
            exit_shell(NULL, 0);
        }

        tokenize(user_input, &receive_argv);

        if (receive_argv == NULL || receive_argv[0] == NULL) {
            free(user_input);
            free(receive_argv);
            continue;
        }

        if (strcmp(receive_argv[0], "exit") == 0) {
            free(user_input);
            free(receive_argv);
            exit_shell(NULL, 0);
        } else if (strcmp(receive_argv[0], "env") == 0) {
            handle_env_command(receive_argv);
        } else {
            execute_command(receive_argv);
        }

        free(user_input);
        free(receive_argv);
    }

    return 0;
}
