#ifndef MENU_H
#define MENU_H

void print_menu(const int *prices, int n);
int price_at(const int *prices, int n, int index);
int max_price(const int *prices, int n);
void reverse_menu(int *prices, int n);
int items_between(const int *start, const int *end);
int drink_length(const char *name);

#endif

