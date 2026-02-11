#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid == 0) { // child runs ls -a -l
    if (execl("/bin/ls", "/bin/ls", "-a", "-l", NULL) == -1) {
      perror("execl");
      exit(EXIT_FAILURE);
    }
    return 0;
  } else { // parent waits for child and then prints its exit status
    int wstatus = 0;
    if (waitpid(pid, &wstatus, 0) == -1) {
      perror("waitpid");
      exit(EXIT_FAILURE);
    }
    if (WIFEXITED(wstatus)) {
      printf("Child finished with exit status: %d", WEXITSTATUS(wstatus));
    } else {
      printf("Child did not exit normally");
    }
  }
}
