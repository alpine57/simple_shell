#include "main.h"
char *fun_getline(void) {
    char *line = NULL;
    size_t buffer_size = BUFFER_SIZE;
    size_t line_size = 0;
    int c;

    line = (char *)malloc(buffer_size * sizeof(char));
    if (line == NULL) {
        perror("Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        c = getchar();

        if (c == EOF || c == '\n') {
            break;
        }

        line[line_size++] = c;

        if (line_size >= buffer_size - 1) {
            char *new_line;
            buffer_size += BUFFER_SIZE;
            new_line = realloc(line, buffer_size * sizeof(char));
            if (new_line == NULL) {
                perror("Error: Memory reallocation failed.\n");
                free(line);
                exit(EXIT_FAILURE);
            }
            line = new_line;
        }
    }

    if (line_size == 0 && c == EOF) {
        free(line);
        return NULL;
    }

    line[line_size] = '\0';
    return line;
}

