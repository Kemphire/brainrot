#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
  pid_t child;
  child = fork();
  if (child < 0) {
    printf("Poblem in fork");
  }
  printf("\nHello world\n");
}
