/*
 * roster.c - Functions for printing, copying, comparing,
 * and changing team names.
 * Author: Christopher Luckey
 */

#include "roster.h"
#include <stdio.h>

void print_team(const char name[])
{
    if (name == NULL) {
        return;
    }

    printf("%s", name);
}

size_t team_len(const char name[])
{
    size_t length = 0;

    if (name == NULL) {
        return 0;
    }

    while (name[length] != '\0') {
        length++;
    }

    return length;
}

void team_copy(char dest[], size_t dest_size, const char src[])
{
    size_t i = 0;

    if (dest == NULL || dest_size == 0) {
        return;
    }

    if (src == NULL) {
        dest[0] = '\0';
        return;
    }

    while (i < dest_size - 1 && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
}

bool team_same(const char a[], const char b[])
{
    size_t i = 0;

    if (a == NULL || b == NULL) {
        return false;
    }

    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return false;
        }
        i++;
    }

    return a[i] == b[i];
}

void shout(char name[])
{
    size_t i = 0;

    if (name == NULL) {
        return;
    }

    while (name[i] != '\0') {
        if (name[i] >= 'a' && name[i] <= 'z') {
            name[i] = (char)(name[i] - 'a' + 'A');
        }
        i++;
    }
}

