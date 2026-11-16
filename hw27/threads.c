#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define THREAD_COUNT 4
#define ITERATIONS 1000000

int counter = 0;
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

void *increment_without_mutex(void *arg) {
  (void)arg;

  for (int i = 0; i < ITERATIONS; i++) {
    counter++;
  }

  return NULL;
}

void *increment_with_mutex(void *arg) {
  (void)arg;

  for (int i = 0; i < ITERATIONS; i++) {
    pthread_mutex_lock(&counter_mutex);
    counter++;
    pthread_mutex_unlock(&counter_mutex);
  }

  return NULL;
}

int main(void) {
  pthread_t threads[THREAD_COUNT];

  printf("Part A: Shared Counter\n");

  counter = 0;
  printf("\nWithout mutex (race condition):\n");

  for (int i = 0; i < THREAD_COUNT; i++) {
    if (pthread_create(&threads[i], NULL, increment_without_mutex, NULL) != 0) {
      fprintf(stderr, "Thread creation failed.\n");
      return EXIT_FAILURE;
    }
  }

  for (int i = 0; i < THREAD_COUNT; i++) {
    if (pthread_join(threads[i], NULL) != 0) {
      fprintf(stderr, "Thread joining failed.\n");
      return EXIT_FAILURE;
    }
  }

  printf("Final counter: %d\n", counter);
  printf("Expected counter: %d\n", THREAD_COUNT * ITERATIONS);


  counter = 0;
  printf("\nWith mutex (protected counter):\n");

  for (int i = 0; i < THREAD_COUNT; i++) {
    if (pthread_create(&threads[i], NULL, increment_with_mutex, NULL) != 0) {
      fprintf(stderr, "Thread creation failed.\n");
      return EXIT_FAILURE;
    }
  }

  for (int i = 0; i < THREAD_COUNT; i++) {
    if (pthread_join(threads[i], NULL) != 0) {
      fprintf(stderr, "Thread joining failed.\n");
      return EXIT_FAILURE;
    }
  }

  printf("Final counter: %d\n", counter);
  printf("Expected counter: %d\n", THREAD_COUNT * ITERATIONS);

  assert(counter == THREAD_COUNT * ITERATIONS);

  pthread_mutex_destroy(&counter_mutex);

  return EXIT_SUCCESS;
}
