#include "main.h"
   
   char *prompt_read(void) {
       char *user_input = NULL;
       ssize_t fd_check = -1;
   
       while (1) {
           if (isatty(STDIN_FILENO) && write(STDOUT_FILENO, "$ ", 2) == -1) {
               perror("write");
              exit(EXIT_FAILURE);
          }
  
          user_input = fun_getline();
  
          if (user_input == NULL) {
              fprintf(stderr, "Error Unable to read input.\n");
              continue;
          }
  
          if (fd_check > 0) {
              break;
          }
      }
  
  
      return user_input;
  }
