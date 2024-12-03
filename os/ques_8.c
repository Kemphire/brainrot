#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

void sjf(int n) {
  int bt[n], wt[n], tat[n], avwt = 0, avtat = 0;
  wt[0] = 0;
  printf("\nEnter process burst time\n");
  for (int i = 0; i < n; i++) {
    printf("Burst time of %d's process: ", i + 1);
    scanf("%d", &bt[i]);
  }
  qsort(bt, n, sizeof(int), compare);
  for (int i = 1; i < n; i++) {
    wt[i] = 0;
    for (int j = 0; j < i; j++) {
      wt[i] += bt[j];
    }
  }

  printf("\n%-10s | %-15s | %-15s | %-15s\n", "Process", "Burst Time",
         "Waiting Time", "Turnaround Time");
  printf("-------------------------------------------------------------\n");

  for (int i = 0; i < n; i++) {
    tat[i] = bt[i] + wt[i];
    avwt += wt[i];
    avtat += tat[i];
    printf("%-10d | %-15d | %-15d | %-15d\n", i + 1, bt[i], wt[i], tat[i]);
  }
  avwt /= n;
  avtat /= n;
  printf("-------------------------------------------------------------\n");
  printf("Average Waiting Time: %-5d\n", avwt);
  printf("Average Turnaround Time: %-5d\n", avtat);
}

int main(void) {
  int n;
  printf("Enter total number of process but process should be less than 25: ");
  scanf("%d", &n);
  if (n > 25) {
    printf("Total number of process should be less than 25\n");
  } else {
    sjf(n);
  }
  return 0;
}
