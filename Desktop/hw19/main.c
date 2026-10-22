/*
 * main.c
 * Demonstrates the intramural score helper functions.
 * Author: Christopher Luckey 
 */

#include <stdio.h>
#include "scores.h"

int main(void)
{
    const int scores[] = {12, 8, 15, 10, 9};
    int n = (int)(sizeof(scores) / sizeof(scores[0]));

    print_scores(scores, n);
    printf("n (sizeof) = %d\n", n);

    printf("score_at 2 = %d\n", score_at(scores, n, 2));
    printf("score_at 9 = %d\n", score_at(scores, n, 9));

    printf("sum = %d\n", sum_scores(scores, n));
    printf("max = %d\n", max_score(scores, n));
    printf("count >= 10: %d\n", count_at_least(scores, n, 10));

    const int board[][GAMES] = {
        {12, 8, 15, 10},
        {9, 11, 7, 14},
        {13, 6, 16, 8}
    };

    int nteams = (int)(sizeof(board) / sizeof(board[0]));

    print_board(board, nteams);
    printf("board sum = %d\n", board_sum(board, nteams));

    print_scores(NULL, 5);
    print_board(NULL, 3);

    return 0;
}
