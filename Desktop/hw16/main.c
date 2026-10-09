/*
 * main.c - Demonstrates pointer arithmetic menu functions.
 * Author: Christopher Luckey
 */

#include <stdio.h>
#include "menu.h"

int main(void)
{
    int prices[] = {250, 350, 450, 199, 500};
    int n = (int)(sizeof(prices) / sizeof(prices[0]));

    printf("menu: ");
    print_menu(prices, n);

    printf("price_at 2 = %d\n", price_at(prices, n, 2));
    printf("price_at 10 = %d\n", price_at(prices, n, 10));
    printf("max = %d\n", max_price(prices, n));

    printf("addr[0] = %p\n", (void *)&prices[0]);
    printf("addr[1] = %p\n", (void *)&prices[1]);
    printf("byte gap = %zu\n",
           (size_t)((char *)&prices[1] - (char *)&prices[0]));

    printf("items 0..4 = %d\n",
           items_between(&prices[0], &prices[4]));

    reverse_menu(prices, n);
    printf("reversed: ");
    print_menu(prices, n);

    printf("drink_length(\"latte\") = %d\n", drink_length("latte"));
    printf("drink_length(NULL) = %d\n", drink_length(NULL));

    return 0;
}

