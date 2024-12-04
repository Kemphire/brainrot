#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *arr;
  int size;
} ArgList;

void *sum(void *);

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "At least 3 args are needed\n");
    exit(1);
  }

  int first_half = (argc - 1) / 2;
  int second_half = (argc - 1) - first_half;

  int *first_arr = malloc(sizeof(int) * first_half);
  int *second_arr = malloc(sizeof(int) * second_half);

  for (int i = 1; i <= first_half; i++) {
    first_arr[i - 1] = atoi(argv[i]);
  }

  for (int i = first_half + 1; i < argc; i++) {
    second_arr[i - (first_half + 1)] = atoi(argv[i]);
  }

  ArgList first_arg = {first_arr, first_half};
  ArgList second_arg = {second_arr, second_half};

  pthread_t tid1, tid2;
  pthread_attr_t attr;

  pthread_attr_init(&attr);

  pthread_create(&tid1, &attr, &sum, &first_arg);
  pthread_create(&tid2, &attr, &sum, &second_arg);

  int *result1, *result2;

  pthread_join(tid1, (void **)&result1);
  pthread_join(tid2, (void **)&result2);

  printf("The sum of the list is -> %d", *((int *)result1) + *((int *)result2));
}

void *sum(void *params) {
  ArgList *args = (ArgList *)params;

  int size = args->size;
  int *sum = malloc(sizeof(int));

  for (int i = 0; i < size; i++) {
    *sum += args->arr[i];
  }
  pthread_exit(sum);
}
