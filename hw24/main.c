/*
 * main.c
 * Demonstrates tagged union functions and tests valid,
 * wrong-kind, and NULL cases.
 */

#include <stdio.h>
#include <stddef.h>
#include "variant.h"

int main(void) {
    struct Stat score_stat;
    struct Stat average_stat;

    /* Test integer score */
    set_score(&score_stat, 18);

    print_stat(&score_stat);

    printf("get_score -> %d\n",
           get_score(&score_stat));

    /* Test floating-point average */
    set_average(&average_stat, 3.50f);

    print_stat(&average_stat);

    printf("get_average -> %.2f\n",
           get_average(&average_stat));

    /* Test wrong-kind getters */
    printf("wrong kind get_average -> %.2f\n",
           get_average(&score_stat));

    printf("wrong kind get_score -> %d\n",
           get_score(&average_stat));

    /* Test memory sizes */
    print_sizes();

    /* Test NULL pointers */
    printf("\nTesting NULL pointers:\n");

    print_stat(NULL);
    set_score(NULL, 1);
    set_average(NULL, 2.5f);

    printf("NULL get_score -> %d\n",
           get_score(NULL));

    printf("NULL get_average -> %.2f\n",
           get_average(NULL));

    printf("NULL tests completed safely.\n");

    return 0;
}

