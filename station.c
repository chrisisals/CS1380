/*
 * station.c
 * Implements dynamic weather reading log operations.
 * Author: Christopher Luckey
 */

#include <stdio.h>
#include <stdlib.h>
#include "station.h"

int *make_log(int n) {
    if (n <= 0) {
        return NULL;
    }

    int *log = malloc((size_t)n * sizeof(int));
    if (log == NULL) {
        return NULL;
    }

    return log;
}

void print_log(const int *log, int n) {
    if (log == NULL || n <= 0) {
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("%d", log[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int max_reading(const int *log, int n) {
    if (log == NULL || n <= 0) {
        return 0;
    }

    int max = log[0];
    for (int i = 1; i < n; i++) {
        if (log[i] > max) {
            max = log[i];
        }
    }

    return max;
}

int *grow_log(int *log, int old_n, int new_n) {
    if (new_n <= old_n) {
        return log;
    }

    if (log == NULL) {
        return make_log(new_n);
    }

    int *temp = realloc(log, (size_t)new_n * sizeof(int));
    if (temp == NULL) {
        return NULL;
    }

    return temp;
}

int *append_reading(int *log, int *n, int value) {
    if (n == NULL) {
        return NULL;
    }

    if (log == NULL && *n != 0) {
        return NULL;
    }

    int *temp = realloc(log, (size_t)(*n + 1) * sizeof(int));
    if (temp == NULL) {
        return NULL;
    }

    temp[*n] = value;
    *n = *n + 1;

    return temp;
}

void free_log(int **log) {
    if (log != NULL) {
        free(*log);
        *log = NULL;
    }
}

