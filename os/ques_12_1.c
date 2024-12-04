#include <stdio.h>

int main(int argc, char **argv) {
  int p, m;

  printf("Enter the number of processes: ");
  scanf("%d", &p);
  printf("Enter the number of memory blocks: ");
  scanf("%d", &m);

  int proc[p], marr[m];

  for (int i = 0; i < p; i++) {
    printf("Enter the size of process %d", i + 1);
    scanf("%d", &proc[i]);
  }

  for (int i = 0; i < p; i++) {
    printf("Enter the size of memory block %d", i + 1);
    scanf("%d", &marr[i]);
  }

  int allocation_failled = 1;

  for (int i = 0; i < p; i++) {
    allocation_failled = 1;
    for (int j = 0; j < m; j++) {
      if (marr[j] >= proc[i]) {
        printf("Allocating process %d in memory block %d, size remainin in "
               "memory %d is %d\n",
               i + 1, j + 1, j + 1, marr[j] - proc[i]);
        marr[j] -= proc[j];
        allocation_failled = 0;
        break;
      }
    }
    if (allocation_failled) {
      fprintf(stderr, "No space for %d process", i + 1);
      break;
    }
  }
}
