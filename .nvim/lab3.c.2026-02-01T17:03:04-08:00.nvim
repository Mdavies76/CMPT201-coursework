#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 5

int printCommand(const char *s) {
  const char *cmd = "print";
  int i = 0;

  while (s[i] && cmd[i]) {
    if (s[i] != cmd[i]) {
      return 0;
    }
    i++;
  }
  return s[i] == '\0' && cmd[i] == '\0';
}

void storeLine(char *buffer[], int index, const char *input, int len) {
  free(buffer[index]);
  buffer[index] = malloc(len + 1);
  memcpy(buffer[index], input, len + 1);
}

void printLines(char *buffer[], int count) {
  int numLines = (count < MAX_LINES) ? count : MAX_LINES;
  int start = count - numLines;
  for (int i = 0; i < numLines; i++) {
    printf("%s\n", buffer[(start + 1) % MAX_LINES]);
  }
}

void _free(char *buffer[]) {
  for (int i = 0; i < MAX_LINES; i++) {
    free(buffer[i]);
  }
}

int main(void) {
  char *lines[MAX_LINES] = {NULL};
  char *input = NULL;
  int len = 0;
  int inputSize;
  int count = 0;

  while (1) {
    printf("Enter input: ");
    inputSize = getline(&input, &len, stdin);
    if (inputSize == -1) {
      break;
    }
    storeLine(lines, count % MAX_LINES, input, inputSize);
    count++;

    if (printCommand(input)) {
      printLines(lines, count);
    }
  }

  _free(lines);
  free(input);
  return 0;
}
