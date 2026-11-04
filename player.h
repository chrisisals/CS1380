#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>

struct Player {
    char name[32];
    int jersey;
    int points;
};

void print_player(const struct Player *p);

void init_player(struct Player *p,
                 const char name[],
                 int jersey,
                 int points);

int get_points(const struct Player *p);

void add_points(struct Player *p, int more);

bool same_jersey(const struct Player *a,
                 const struct Player *b);

#endif
