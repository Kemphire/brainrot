#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int child = fork();
  if (child < 0) {
    fprintf(stderr, "Problem in fork\n");
    exit(EXIT_FAILURE);
  } else if (child == 0) {
    char *args[3];
    args[0] = "/bin/eza";
    args[1] = (char *)0;
    execvp(args[0], args);
  } else {
    wait(NULL);
    printf("Hey i'm parent process and i'm executing something else\n");
  }
}
