/*
 * prices.c
 * Defines helper functions for working with price pointers.
 * Name: Christopher Luckey
 */

#include "prices.h"
#include <stdio.h>

void swap_cents(int *a, int *b)
{
    if (a == NULL || b == NULL)
    {
        return;
    }

    int temp = *a;
    *a = *b;
    *b = temp;
}

void set_price(int *price_cents, int new_cents)
{
    if (price_cents == NULL)
    {
        return;
    }

    *price_cents = new_cents;
}

void print_price(const char *name, const int *price_cents)
{
    if (price_cents == NULL)
    {
        printf("%s: missing price (null)\n", name);
        return;
    }

    printf("%s: %d cents\n", name, *price_cents);
}

void retarget(int **current, int *other)
{
    if (current == NULL || other == NULL)
    {
        return;
    }

    *current = other;
}
