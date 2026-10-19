/*
 * menu.c - Implements menu functions using pointer arithmetic.
 * Author: Christopher Luckey
 */

#include <stdio.h>
#include "menu.h"

void print_menu(const int *prices, int n)
{
    if (prices == NULL || n <= 0) {
        return;
    }

    const int *p = prices;

    for (; p < prices + n; p++) {
        printf("%d ", *p);
    }

    printf("\n");
}

int price_at(const int *prices, int n, int index)
{
    if (prices == NULL || n <= 0 || index < 0 || index >= n) {
        return 0;
    }

    return *(prices + index);
}

int max_price(const int *prices, int n)
{
    if (prices == NULL || n <= 0) {
        return 0;
    }

    int maximum = *prices;

    for (const int *p = prices + 1; p < prices + n; p++) {
        if (*p > maximum) {
            maximum = *p;
        }
    }

    return maximum;
}

void reverse_menu(int *prices, int n)
{
    if (prices == NULL || n <= 1) {
        return;
    }

    int *start = prices;
    int *end = prices + n - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int items_between(const int *start, const int *end)
{
    if (start == NULL || end == NULL) {
        return 0;
    }

    return (int)(end - start);
}

int drink_length(const char *name)
{
    if (name == NULL) {
        return 0;
    }

    const char *p = name;

    while (*p != '\0') {
        p++;
    }

    return (int)(p - name);
}
