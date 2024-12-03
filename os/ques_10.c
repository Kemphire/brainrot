#include <limits.h>
#include <stdio.h>

typedef struct {
  int id;
  int arrival;
  int burst;
  int remaining;
  int completion;
  int waiting;
  int turnaround;
} Process;

void srtf(int n) {
  Process p[n];
  int total_completed = 0, current_time = 0;
  int min_remaining_index, min_remaining_time;

  printf("Enter arrival time and burst time for each process:\n");
  for (int i = 0; i < n; i++) {
    p[i].id = i + 1;
    printf("Process %d Arrival Time: ", i + 1);
    scanf("%d", &p[i].arrival);
    printf("Process %d Burst Time: ", i + 1);
    scanf("%d", &p[i].burst);
    p[i].remaining = p[i].burst;
  }

  while (total_completed < n) {
    min_remaining_time = INT_MAX;
    min_remaining_index = -1;

    for (int i = 0; i < n; i++) {
      if (p[i].arrival <= current_time && p[i].remaining > 0 &&
          p[i].remaining < min_remaining_time) {
        min_remaining_time = p[i].remaining;
        min_remaining_index = i;
      }
    }

    if (min_remaining_index == -1) {
      current_time++;
      continue;
    }

    p[min_remaining_index].remaining--;
    current_time++;

    if (p[min_remaining_index].remaining == 0) {
      total_completed++;
      p[min_remaining_index].completion = current_time;
      p[min_remaining_time].turnaround =
          p[min_remaining_index].completion - p[min_remaining_index].arrival;
      p[min_remaining_index].waiting =
          p[min_remaining_index].turnaround - p[min_remaining_index].burst;
    }
  }

  printf("\n%-10s | %-15s | %-15s | %-15s | %-15s | %-15s\n", "Process",
         "Arrival Time", "Burst Time", "Completion Time", "Turnaround Time",
         "Waiting Time");
  printf("---------------------------------------------------------------------"
         "---\n");

  int total_waiting = 0, total_turnaround = 0;
  for (int i = 0; i < n; i++) {
    printf("%-10d | %-15d | %-15d | %-15d | %-15d | %-15d\n", p[i].id,
           p[i].arrival, p[i].burst, p[i].completion, p[i].turnaround,
           p[i].waiting);
    total_waiting += p[i].waiting;
    total_turnaround += p[i].turnaround;
  }

  printf("---------------------------------------------------------------------"
         "---\n");
  printf("Average Waiting Time: %.2f\n", (float)total_waiting / n);
  printf("Average Turnaround Time: %.2f\n", (float)total_turnaround / n);
}

int main() {
  int n;
  printf("Enter total number of processes: ");
  scanf("%d", &n);
  if (n <= 0) {
    printf("Number of processes must be greater than 0.\n");
    return 1;
  }

  srtf(n);
  return 0;
}
