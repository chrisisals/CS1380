#ifndef SCORES_H
#define SCORES_H

static constexpr int GAMES = 4;

void print_scores(const int scores[], int n);
int score_at(const int scores[], int n, int index);
int sum_scores(const int scores[], int n);
int max_score(const int scores[], int n);
int count_at_least(const int scores[], int n, int threshold);

void print_board(const int board[][GAMES], int nteams);
int board_sum(const int board[][GAMES], int nteams);

#endif
