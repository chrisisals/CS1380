/*
 * main.c - Demonstrates dynamic memory allocation for a weather station.
 * Author: Christopher Luckey
 */

#include <stdio.h>
#include "station.h"

int main(void)
{
    int n = 5;

    int *log = make_log(n);

    if (log == NULL) {
        fprintf(stderr, "Error: could not allocate temperature log.\n");
        return 1;
    }

    log[0] = 68;
    log[1] = 71;
    log[2] = 64;
    log[3] = 72;
    log[4] = 70;

    print_log(log, n);

    printf("reading_at 2 = %d\n", reading_at(log, n, 2));
    printf("max = %d\n", max_reading(log, n));

    int *zero_log = make_zero_log(n);

    if (zero_log == NULL) {
        fprintf(stderr, "Error: could not allocate zero log.\n");
        free_log(&log);
        return 1;
    }

    printf("calloc zeros:");

    for (int i = 0; i < n; i++) {
        printf(" %d", reading_at(zero_log, n, i));
    }

    printf("\n");

    printf("NULL tests:\n");
    print_log(NULL, n);
    printf("reading_at(NULL, 5, 0) = %d\n", reading_at(NULL, 5, 0));

    int *already_null = NULL;
    free_log(&already_null);
    printf("free_log on NULL pointer: safe\n");

    free_log(&log);
    printf("after free_log, pointer is %s\n",
           log == NULL ? "NULL" : "not NULL");

    free_log(&zero_log);

    return 0;
}
