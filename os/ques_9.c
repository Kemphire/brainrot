#include <stdio.h>

typedef struct {
  int id;
  int arrival;
  int priority;
  int completion;
  int burst;
  int waiting;
  int turnaround;
} Process;

void swap(Process *a, Process *b) {
  Process temp = *a;
  *a = *b;
  *b = temp;
}

void sort_by_priority_and_arrival(Process p[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (p[j].priority > p[j + 1].priority ||
          (p[j].priority == p[j + 1].priority &&
           p[j].arrival > p[j + 1].arrival)) {
        swap(&p[j], &p[j + 1]);
      }
    }
  }
}
void calculate_times(Process p[], int n) {
  int current_time = 0;
  for (int i = 0; i < n; i++) {
    if (p[i].arrival > current_time) {
      current_time = p[i].arrival;
    }
    p[i].completion = current_time + p[i].burst;
    p[i].turnaround = p[i].completion - p[i].arrival;
    p[i].waiting = p[i].turnaround - p[i].burst;
    current_time = p[i].completion;
  }
}
void print_table(Process p[], int n) {
  printf("\n%-10s | %-10s | %-15s | %-15s | %-15s\n", "PID", "Burst Time",
         "Waiting Time", "Turnaround Time", "Priority");
  printf("----------------------------------------------------------------------------------------------\n");


  for (int i = 0; i < n; i++) {
    printf("%-10d | %-10d | %-15d | %-15d | %-15d | %-15d\n", p[i].id, i + 1,
           p[i].burst, p[i].waiting, p[i].turnaround, p[i].priority);
  }
}

int main() {
  int n;
  printf("Enter the number of processes: ");
  scanf("%d", &n);

  Process p[n];
  printf("Enter Arrival Time, Burst Time, and Priority for each process:\n");
  for (int i = 0; i < n; ++i) {
    p[i].id = i + 1;
    printf("Process %d: ", i + 1);
    scanf("%d %d %d", &p[i].arrival, &p[i].burst, &p[i].priority);
  }

  sort_by_priority_and_arrival(p, n);

  calculate_times(p, n);

  print_table(p, n);

  return 0;
}
