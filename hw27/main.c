
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10000
#define THREAD_COUNT 4

int numbers[ARRAY_SIZE];

struct ThreadData {
  int start;
  int end;
  long long partial_sum;
};

void *sum_array(void *arg) {
  struct ThreadData *data = arg;

  data->partial_sum = 0;

  for (int i = data->start; i < data->end; i++) {
    data->partial_sum += numbers[i];
  }

  return NULL;
}

int main(void) {
  pthread_t threads[THREAD_COUNT];
  struct ThreadData data[THREAD_COUNT];

  for (int i = 0; i < ARRAY_SIZE; i++) {
    numbers[i] = i + 1;
  }

  for (int i = 0; i < THREAD_COUNT; i++) {
    data[i].start = i * (ARRAY_SIZE / THREAD_COUNT);
    data[i].end = (i + 1) * (ARRAY_SIZE / THREAD_COUNT);
    data[i].partial_sum = 0;

    if (pthread_create(&threads[i], NULL, sum_array, &data[i]) != 0) {
      fprintf(stderr, "Thread creation failed.\n");
      return EXIT_FAILURE;
    }
  }

  long long parallel_total = 0;

  for (int i = 0; i < THREAD_COUNT; i++) {
    if (pthread_join(threads[i], NULL) != 0) {
      fprintf(stderr, "Thread joining failed.\n");
      return EXIT_FAILURE;
    }

    parallel_total += data[i].partial_sum;
  }

  long long sequential_total = 0;

  for (int i = 0; i < ARRAY_SIZE; i++) {
    sequential_total += numbers[i];
  }

  if (parallel_total != sequential_total) {
    fprintf(stderr, "ERROR: Totals do not match!\n");
    return EXIT_FAILURE;
  }

    printf("Parallel total: %lld\n", parallel_total);
    printf("Sequential total: %lld\n", sequential_total);

    return EXIT_SUCCESS;
  }
