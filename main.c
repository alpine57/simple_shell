#include "main.h"
#include "main.h"
char *input;

int main(int ac, char **argv) {
     (void)ac;
    (void)argv;
    printf("Enter text ('$' to quit):\n");

    while ((input = prompt_read()) != NULL) {
        if (input[0] == '$' && input[1] == '\0') {
            free(input);
            break;
        }

        printf("You entered: %s\n", input);
        free(input);
    }

    return 0;
}

