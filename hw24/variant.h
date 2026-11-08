
#ifndef VARIANT_H
#define VARIANT_H

enum StatKind {
    STAT_SCORE = 0,
    STAT_AVERAGE = 1
};

union StatValue {
    int score;
    float average;
};

struct Stat {
    enum StatKind kind;
    union StatValue value;
};

/* Function prototypes */

void print_stat(const struct Stat *s);

void set_score(struct Stat *s, int score);

void set_average(struct Stat *s, float average);

int get_score(const struct Stat *s);

float get_average(const struct Stat *s);

void print_sizes(void);

#endif

