/*
 * Prints, searches, and updates a 2D picture of integer codes.
 * Name: Christopher Luckey
 */

#include "picture.h"
#include <stddef.h>
#include <stdio.h>

void print_picture(const int pic[][COLS], int nrows)
{
    if (pic == NULL || nrows <= 0) {
        return;
    }

    for (int r = 0; r < nrows; r++) {
        for (int c = 0; c < COLS; c++) {
            if (pic[r][c] == 0) {
                printf(".");
            } else if (pic[r][c] == 1) {
                printf("#");
            } else {
                printf("?");
            }
        }
        printf("\n");
    }
}

int find_code(const int pic[][COLS], int nrows, int target)
{
    if (pic == NULL || nrows <= 0) {
        return -1;
    }

    for (int r = 0; r < nrows; r++) {
        for (int c = 0; c < COLS; c++) {
            if (pic[r][c] == target) {
                return r * COLS + c;
            }
        }
    }

    return -1;
}

void set_cell(int pic[][COLS], int nrows, int row, int col, int value)
{
    if (pic == NULL || nrows <= 0) {
        return;
    }

    if (row >= 0 && row < nrows && col >= 0 && col < COLS) {
        pic[row][col] = value;
    }
}
