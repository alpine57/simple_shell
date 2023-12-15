#include "main.h"

char *fun_getline(void) {
    char *line = NULL;
    ssize_t line_size = 0;
    ssize_t buffer_size = BUFFER_SIZE;
    ssize_t index = 0;
    int c;

    line = (char *)malloc(buffer_size * sizeof(char));
    if (line == NULL) {
        perror("Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        c = getchar();

        if (c == EOF || c == '\n') {
            line[index] = '\0';
            break;
        }

        line[index++] = (char)c;

       
        if (index >= buffer_size - 1) {
            buffer_size += BUFFER_SIZE;
            char *temp = realloc(line, buffer_size * sizeof(char));
            if (temp == NULL) {
                perror("Error: Memory reallocation failed.\n");
                free(line);
                exit(EXIT_FAILURE);
            }
            line = temp;
        }
    }

   
    if (line_size == 0 && c == EOF) {
        free(line);
        return NULL;
    }

    return line;
}

