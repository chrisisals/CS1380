#ifndef PRICES_H
#define PRICES_H

void swap_cents(int *a, int *b);
void set_price(int *price_cents, int new_cents);
void print_price(const char *name, const int *price_cents);
void retarget(int **current, int *other);

#endif
