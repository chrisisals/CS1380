/*
 * variant.c
 * Implements tagged union helper functions for storing
 * either an integer score or a floating-point average.
 */

#include <stdio.h>
#include "variant.h"

void print_stat(const struct Stat *s) {
    if (s == NULL) {
        return;
    }

    switch (s->kind) {
        case STAT_SCORE:
            printf("Score: %d\n", s->value.score);
            break;

        case STAT_AVERAGE:
            printf("Average: %.2f\n", s->value.average);
            break;

        default:
            printf("Unknown kind\n");
            break;
    }
}

void set_score(struct Stat *s, int score) {
    if (s == NULL) {
        return;
    }

    s->kind = STAT_SCORE;
    s->value.score = score;
}

void set_average(struct Stat *s, float average) {
    if (s == NULL) {
        return;
    }

    s->kind = STAT_AVERAGE;
    s->value.average = average;
}

int get_score(const struct Stat *s) {
    if (s == NULL || s->kind != STAT_SCORE) {
        return 0;
    }

    return s->value.score;
}

float get_average(const struct Stat *s) {
    if (s == NULL || s->kind != STAT_AVERAGE) {
        return 0.0f;
    }

    return s->value.average;
}

void print_sizes(void) {
    printf("sizeof union StatValue: %zu bytes\n",
           sizeof(union StatValue));

    printf("sizeof struct Stat: %zu bytes\n",
           sizeof(struct Stat));
}
