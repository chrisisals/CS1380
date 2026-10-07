/*
 * main.c
 * Demonstrates pointers, NULL, pointer-to-pointer, and arrays of prices.
 * Name: Christopher Luckey
 */

#include <stdio.h>
#include "prices.h"

int main(void)
{
    int latte = 350;
    int mocha = 400;
    int tea = 250;

    int *pointer = &latte;

    printf("latte=%d addr=%p tag=%p *tag=%d\n",
           latte, (void *)&latte, (void *)pointer, *pointer);

    set_price(pointer, 400);

    printf("after set_price: latte=%d\n", latte);

    swap_cents(&mocha, &latte);

    printf("swap mocha %d with latte %d -> latte=%d mocha=%d\n",
           400, 400, latte, mocha);

    print_price("missing tag", NULL);

    int *special = &mocha;

    printf("special was mocha %d; ", *special);

    retarget(&special, &tea);

    printf("after retarget, special is tea %d\n", *special);

    int board[3] = {450, 400, 250};
    int *p = board;

    printf("board: %d %d %d\n", *(p + 0), *(p + 1), *(p + 2));

    return 0;
}
