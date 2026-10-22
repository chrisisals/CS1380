/*
 * scores.c
 * Implements helper functions for intramural scores and scoreboards.
 * Author: Christopher Luckey
 */

#include <stdio.h>
#include "scores.h"

void print_scores(const int scores[], int n)
{
    if (scores == NULL || n <= 0) {
        return;
    }

    printf("scores:");
    for (int i = 0; i < n; i++) {
        printf(" %d", scores[i]);
    }
    printf("\n");
}

int score_at(const int scores[], int n, int index)
{
    if (scores == NULL || n <= 0 || index < 0 || index >= n) {
        return 0;
    }

    return scores[index];
}

int sum_scores(const int scores[], int n)
{
    if (scores == NULL || n <= 0) {
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += scores[i];
    }

    return sum;
}

int max_score(const int scores[], int n)
{
    if (scores == NULL || n <= 0) {
        return 0;
    }

    int max = scores[0];
    for (int i = 1; i < n; i++) {
        if (scores[i] > max) {
            max = scores[i];
        }
    }

    return max;
}

int count_at_least(const int scores[], int n, int threshold)
{
    if (scores == NULL || n <= 0) {
        return 0;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (scores[i] >= threshold) {
            count++;
        }
    }

    return count;
}

void print_board(const int board[][GAMES], int nteams)
{
    if (board == NULL || nteams <= 0) {
        return;
    }

    printf("board:\n");
    for (int row = 0; row < nteams; row++) {
        for (int col = 0; col < GAMES; col++) {
            printf("%3d", board[row][col]);
            if (col < GAMES - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int board_sum(const int board[][GAMES], int nteams)
{
    if (board == NULL || nteams <= 0) {
        return 0;
    }

    int sum = 0;
    for (int row = 0; row < nteams; row++) {
        for (int col = 0; col < GAMES; col++) {
            sum += board[row][col];
        }
    }

    return sum;
}
