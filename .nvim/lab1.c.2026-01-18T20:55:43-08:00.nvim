#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  char *line = NULL;
  size_t n = 0;
  printf("Enter a message: \n");
  if (getline(&line, &n, stdin) != -1) {
    printf("Tokens:\n");
    char *ret = NULL;
    char *saveptr = NULL;
    char *str = line;
    while ((ret = strtok_r(str, " ", &saveptr))) {
      printf("%s\n", ret);
      str = NULL;
    }
  } else {
    printf("Cannot read line.\n");
  }
  return 0;
}
