#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 100

int fcopy(int source_file, int destination_file) {
  char buf[BUFFER_SIZE];
  ssize_t bytes_read;
  while ((bytes_read = read(source_file, buf, BUFFER_SIZE)) > 0) {
    if (write(destination_file, buf, bytes_read) != bytes_read) {
      perror("Issue in write");
      return -1;
    }
  }
  if (bytes_read < 0) {
    perror("Error in readin destination_fileg");
    return -1;
  }

  return 0;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <source_file> <destination_file>", argv[0]);
    exit(1);
  }
  char *source_file = argv[1];
  char *destination_file = argv[2];

  int source_fd = open(source_file, O_RDONLY);
  if (source_fd < 0) {
    perror("Source file opening failled");
    exit(1);
  }

  int destination_fd =
      open(destination_file, O_WRONLY | O_TRUNC | O_CREAT, 0644);

  if (destination_fd < 0) {
    perror("Source file opening failled");
    exit(1);
  }

  if (fcopy(source_fd, destination_fd) < 0) {
    fprintf(stderr, "Error in fcopy");
  }

  close(source_fd);
  close(destination_fd);

  return 0;
}
