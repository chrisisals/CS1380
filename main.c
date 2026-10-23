/*
 * Demonstrates printing, searching and updating a console picture.
 * Name: Christopher Luckey 
 */

#include "picture.h"
#include <stddef.h>
#include <stdio.h>

int main(void)
{
    int pic[][COLS] = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    int nrows = (int)(sizeof pic / sizeof pic[0]);

    printf("Original picture:\n");
    print_picture(pic, nrows);

    printf("find 1 -> %d\n", find_code(pic, nrows, 1));
    printf("find 9 -> %d\n", find_code(pic, nrows, 9));

    set_cell(pic, nrows, 2, 2, 1);
    printf("After set_cell(2, 2, 1):\n");
    print_picture(pic, nrows);

    set_cell(pic, nrows, 9, 0, 1);
    printf("set_cell(9, 0, 1) ignored\n");

    printf("Null picture test:\n");
    print_picture(NULL, 4);
    printf("find_code(NULL, 4, 1) -> %d\n", find_code(NULL, 4, 1));

    return 0;
}
