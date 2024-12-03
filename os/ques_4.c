#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int status =
      system("awk -F': ' '/model name/  {print $2;exit}' /proc/cpuinfo");
  int status2 =
      system("awk -F': ' '/vendor_id/ {print $2;exit;}' /proc/cpuinfo");
  int status3 =
      system("awk -F': ' '/cpu cores/ {print $2;exit;}' /proc/cpuinfo");
  if (status != 0 || status2 != 0 || status3 != 0) {
    printf("something is wrong\n");
  }
}
