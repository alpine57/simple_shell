#include "main.h"

char *fun_getline(void) {
    static char buffer[BUFFER_SIZE];
    static int buffer_pos = 0;
    static int buffer_size = 0;

    char *line = NULL;
    int line_size = 0;
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
            if (line == NULL) {
                line = (char *)malloc((line_size + 1) * sizeof(char));
                if (line == NULL) {
                    perror("Error: Memory allocation failed.\n");
                    exit(EXIT_FAILURE);
                }
            } else {
                line = (char *)realloc(line, (line_size + 1) * sizeof(char));
                if (line == NULL) {
                    perror("Error: Memory reallocation failed.\n");
                    exit(EXIT_FAILURE);
                }
            }

            line[line_size++] = '\0';
            break;
        }

        if (line_size == 0) {
            line = (char *)malloc(BUFFER_SIZE * sizeof(char));
            if (line == NULL) {
                perror("Error: Memory allocation failed.\n");
                exit(EXIT_FAILURE);
            }
        } else if (line_size % BUFFER_SIZE == 0) {
            line = (char *)realloc(line, (line_size + BUFFER_SIZE) * sizeof(char));
            if (line == NULL) {
                perror("Error: Memory reallocation failed.\n");
                exit(EXIT_FAILURE);
            }
        }

        line[line_size++] = c;
    }

    return line;
}

