#include <stdio.h>
#include <unistd.h>

int main() {
  fork();
  for (int i = 0; i < 10; i++) {
    printf("%d ", i);
    fflush(stdout);
    sleep(1);
  }
  printf("\n");
  return 0;
}
