#include "main.h"
/**
 * get_path - finds the full path of a command in the PATH environment variable
 * @first_command: the command to find in the PATH
 * Returns: the full path to the command if found, otherwise NULL
 */
char *get_path(char *first_command) {
    char *cmd_path = getenv("PATH");

    if (access(first_command, F_OK) == 0) {
        return strdup(first_command);
    }

    if (cmd_path) {
        char *path = strdup(cmd_path);
        char *delimiter = ":";
        char *token = strtok(path, delimiter);

        while (token != NULL) {
            char *path_to_file = (char *)malloc(strlen(token) + strlen(first_command) + 2);

            if (path_to_file == NULL) {
                fprintf(stderr, "Memory allocation error.\n");
                exit(EXIT_FAILURE);
            }

            strcpy(path_to_file, token);
            strcat(path_to_file, "/");
            strcat(path_to_file, first_command);

            if (access(path_to_file, F_OK) == 0) {
                free(path);
                return path_to_file;
            }

            free(path_to_file);
            token = strtok(NULL, delimiter);
        }

        free(path);
    }

    return NULL;
}
int cd_dir(char *path) {
    char *new_directory;
    int result;

    if (path == NULL || strcmp(path, "-") == 0) {
        new_directory = getenv("HOME");
        if (new_directory == NULL) {
            fprintf(stderr, "Error: HOME environment variable not set.\n");
            return -1;
        }
    } else {
        new_directory = path;
    }

    result = chdir(new_directory);
    if (result == -1) {
        perror("chdir");
        return -1;
    }

    setenv("PWD", new_directory, 1);

    return 0;
}

