#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int status1 = system("echo 'Total Memory ' && awk -F':' '/MemTotal/ {print "
                       "$2;exit}' /proc/meminfo");
  int status2 =
      system("echo 'Total Free Memory ' && awk -F':' '/MemFree/ {print "
             "$2;exit}' /proc/meminfo");
  int status3 = system("echo 'Total Used Memory ' && awk -F':' '/MemAvailable/ "
                       "{print $2;exit}' /proc/meminfo");
  if (status1 != 0 || status2 != 0 || status3 != 0) {
    fprintf(stderr, "Something went wrong\n");
    exit(1);
  }
}
