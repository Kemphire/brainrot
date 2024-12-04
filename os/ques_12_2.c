#include <stdio.h>

int main() {
  int p, m;
  printf("Enter number of processes: ");
  scanf("%d", &p);
  printf("Enter number of Memory blocks: ");
  scanf("%d", &m);

  int parr[p], marr[m];
  for (int i = 0; i < p; i++) {
    printf("Enter size of process %d: ", i + 1);
    scanf("%d", &parr[i]);
  }
  printf("\n\n");
  for (int i = 0; i < m; i++) {
    printf("Enter size of memory %d: ", i + 1);
    scanf("%d", &marr[i]);
  }
  int allocation_failled, smallest_block_index, smallest_block;
  for (int i = 0; i < p; i++) {
    smallest_block = -1;
    smallest_block_index = -1;
    allocation_failled = 1;
    for (int j = 0; j < m; j++) {
      if ((marr[j] < smallest_block || smallest_block == -1) &&
          marr[j] >= parr[i]) {
        smallest_block = marr[j];
        smallest_block_index = j;
        allocation_failled = 0;
      }
    }
    if (!allocation_failled) {
      marr[smallest_block_index] -= parr[i];
      printf("Allocating process %d to memory block %d\n", i + 1,
             smallest_block_index + 1);
      printf("Size remaining in block %d after allocation: %d\n\n",
             smallest_block_index + 1, marr[smallest_block_index]);
    } else {
      printf("Not enough memory for the process %d\n", i + 1);
    }
  }
  for (int i = 0; i < m; i++) {
    printf("Fragmentation left in each memory block %d is %d\n", i + 1,
           marr[i]);
  }
}
