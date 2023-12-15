#include "main.h"
void exit_shell(char **receive_argv, int execution_status) {
    if (receive_argv && receive_argv[1] != NULL) {
        char *arg_str = receive_argv[1];
        char *endptr;
        long arg = strtol(arg_str, &endptr, 10);

        if (*endptr == '\0' && endptr != arg_str) {
            if (arg >= 0) {
                free(receive_argv);
                exit((int)arg);
            } else {
                fprintf(stderr, "Error: Illegal number: %ld\n", arg);
            }
        } else {
            fprintf(stderr, "Error: Invalid number format: %s\n", arg_str);
        }
    } else {
        if (receive_argv)
            free(receive_argv);
        exit(execution_status);
    }
}
