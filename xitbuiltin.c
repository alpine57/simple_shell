#include "main.h"

void exit_shell(char **receive_argv, int execution_status) {
    if (receive_argv[1] != NULL) {
        int arg = atoi(receive_argv[1]);
        if (arg >= 0) {
            free(receive_argv);
            exit(arg);
        } else {
            fprintf(stderr, "Error: Illegal number: %s\n", receive_argv[1]);
        }
    } else {
        free(receive_argv);
        exit(execution_status);
    }
}

