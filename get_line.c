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
              break;
          }
  
          if (line == NULL) {
             line = (char *)malloc(BUFFER_SIZE * sizeof(char));
              if (line == NULL) {
                  perror("Error: Memory allocation failed.\n");
                  exit(EXIT_FAILURE);
              }
          }
  
         line[line_size++] = c;
      }
  
      if (line_size > 0) {
          line[line_size] = '\0';
      }
  
      return line;
  }
  
