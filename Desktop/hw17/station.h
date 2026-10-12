#ifndef STATION_H
#define STATION_H

int *make_log(int n);
int *make_zero_log(int n);
void print_log(const int *log, int n);
int reading_at(const int *log, int n, int index);
int max_reading(const int *log, int n);
void free_log(int **log);

#endif
