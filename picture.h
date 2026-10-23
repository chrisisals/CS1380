#ifndef PICTURE_H
#define PICTURE_H

static constexpr int COLS = 5;

void print_picture(const int pic[][COLS], int nrows);
int find_code(const int pic[][COLS], int nrows, int target);
void set_cell(int pic[][COLS], int nrows, int row, int col, int value);

#endif
