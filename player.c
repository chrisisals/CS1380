
#include "player.h"

/*
 * player.c
 * Implements functions for creating, printing,
 * updating, and comparing player structures.
 */

#include <stdio.h>
#include "player.h"

void print_player(const struct Player *p)
{
    if (p == NULL) {
        return;
    }

    printf("Name: %s  Jersey: %d  Points: %d\n",
           p->name, p->jersey, p->points);
}

void init_player(struct Player *p,
                 const char name[],
                 int jersey,
                 int points)
{
    if (p == NULL) {
        return;
    }

    if (name == NULL) {
        p->name[0] = '\0';
    } else {
        int i = 0;

        while (i < 31 && name[i] != '\0') {
            p->name[i] = name[i];
            i++;
        }

        p->name[i] = '\0';
    }

    p->jersey = jersey;
    p->points = points;
}

int get_points(const struct Player *p)
{
    if (p == NULL) {
        return 0;
    }

    return p->points;
}

void add_points(struct Player *p, int more)
{
    if (p == NULL) {
        return;
    }

    p->points += more;
}

bool same_jersey(const struct Player *a,
                 const struct Player *b)
{
    if (a == NULL || b == NULL) {
        return false;
    }

    return a->jersey == b->jersey;
}

