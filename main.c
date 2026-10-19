/*
 * main.c
 * Demonstrates the weather station log functions.
 * Author: Christopher Luckey
 */

#include <stdio.h>
#include <stdlib.h>
#include "station.h"

int main(void) {
    int n = 3;
    int *log = make_log(n);

    if (log == NULL) {
        fprintf(stderr, "Could not allocate initial log.\n");
        return 1;
    }

    log[0] = 68;
    log[1] = 71;
    log[2] = 64;

    printf("start n=%d: ", n);
    print_log(log, n);

    int *temp = grow_log(log, n, 6);
    if (temp == NULL) {
        fprintf(stderr, "Could not grow log.\n");
        free_log(&log);
        return 1;
    }

    log = temp;
    log[3] = 72;
    log[4] = 70;
    log[5] = 67;
    n = 6;

    printf("after grow n=%d: ", n);
    print_log(log, n);

    temp = append_reading(log, &n, 69);
    if (temp == NULL) {
        fprintf(stderr, "Could not append reading.\n");
        free_log(&log);
        return 1;
    }
    log = temp;

    temp = append_reading(log, &n, 65);
    if (temp == NULL) {
        fprintf(stderr, "Could not append reading.\n");
        free_log(&log);
        return 1;
    }
    log = temp;

    printf("after append n=%d: ", n);
    print_log(log, n);

    printf("max = %d\n", max_reading(log, n));

    printf("NULL log test: ");
    print_log(NULL, 3);
    printf("NULL max test = %d\n", max_reading(NULL, 3));

    free_log(&log);
    printf("after free_log, pointer is %s\n",
           log == NULL ? "NULL" : "not NULL");

    free_log(&log);

    return 0;
}



