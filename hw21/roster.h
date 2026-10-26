
#ifndef ROSTER_H
#define ROSTER_H

#include <stdbool.h>
#include <stddef.h>

void print_team(const char name[]);
size_t team_len(const char name[]);
void team_copy(char dest[], size_t dest_size, const char src[]);
bool team_same(const char a[], const char b[]);
void shout(char name[]);

#endif

