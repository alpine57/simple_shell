#include "main.h"

char l;
static char buffer[BUFFER_SIZE];
static size_t buffer_pos = 0;
static size_t buffer_size = 0;

char *fun_getline() {
    char *line = NULL;
    size_t line_size = 0;
    size_t line_index = 0;

    while (1) {
        if (buffer_pos >= buffer_size) {
            buffer_size = fread(buffer, 1, BUFFER_SIZE, stdin);
            if (buffer_size == 0) {
                if (line_index == 0) {
                    return NULL;
                } else {
                    break;
                }
            }
            buffer_pos = 0;
        }

        l = buffer[buffer_pos++];

        if (l == '\n') {
            break;
        }

        if (line_index == line_size) {
            line_size += BUFFER_SIZE;
            line = realloc(line, line_size);
            if (!line) {
                perror("Memory allocation error");
                exit(EXIT_FAILURE);
            }
        }

        line[line_index++] = l;
    }

    if (line_index == 0) {
        return NULL;
    }

    line[line_index] = '\0';
    return line;
}
