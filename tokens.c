#include "main.h"

#define BUFFER_SIZE 1024

char buffer[BUFFER_SIZE];

char *fun_getline(void) {
    char *line = NULL;
    int line_size = 0;
    int buffer_pos = 0;
    int buffer_size = 0;
    char c;

    while (1) {
        if (buffer_pos >= buffer_size) {
            buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            buffer_pos = 0;

            if (buffer_size <= 0) {
                if (line_size == 0) {
                    return NULL;
                } else {
                    break;
                }
            }
        }

        c = buffer[buffer_pos++];

        if (c == '\n' || c == '\0') {
            line = realloc(line, (line_size + 1) * sizeof(char));
            if (line == NULL) {
                perror("Error: Memory allocation failed.\n");
                exit(EXIT_FAILURE);
            }
            line[line_size] = '\0';
            break;
        }

        if (line_size % BUFFER_SIZE == 0) {
            char *temp = realloc(line, (line_size + BUFFER_SIZE) * sizeof(char));
            if (temp == NULL) {
                perror("Error: Memory reallocation failed.\n");
                if (line != NULL) free(line);
                exit(EXIT_FAILURE);
            }
            line = temp;
        }

        line[line_size++] = c;
    }

    return line;
}
