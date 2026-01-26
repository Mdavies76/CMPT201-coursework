#include <stdio.h>
#include <stdlib.h>
int main() {
  pid_t pid = fork();
  if (pid != 0) {
    int wstatus = 0;
    if (waitpid(pid, &wstatus, 0) == -1) {
      exit(EXIT_FAILURE);
    }
    if (WIFEXITED(wstatus)) {
      printf("CHild done: %d\n", WEXITSTATUS(wstatus));
    } else {
      printf("Child exited abnormally\n");
    }
  } else {
    if (execlp("ls", "ls", "-a", "-l", NULL) == -1) {
