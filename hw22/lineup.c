/*
 * File: lineup.c
 * Author: Christopher Luckey
 * Description: Implements safe lineup label string functions.
 */

#include "lineup.h"
#include <stdio.h>
#include <string.h>

void print_label(const char label[])
{
    if (label == NULL)
    {
        return;
    }

    printf("%s\n", label);
}

int label_len(const char label[])
{
    if (label == NULL)
    {
        return 0;
    }

    return (int)strlen(label);
}

void safe_copy(char dest[], int dest_size, const char src[])
{
    if (dest == NULL || dest_size <= 0)
    {
        return;
    }

    if (src == NULL)
    {
        dest[0] = '\0';
        return;
    }

    strncpy(dest, src, (size_t)(dest_size - 1));
    dest[dest_size - 1] = '\0';
}

void safe_join(char dest[], int dest_size, const char extra[])
{
    if (dest == NULL || dest_size <= 0 || extra == NULL)
    {
        return;
    }

    int len = 0;

    while (len < dest_size && dest[len] != '\0')
    {
        len++;
    }

    if (len == dest_size)
    {
        dest[dest_size - 1] = '\0';
        len = dest_size - 1;
    }

    int remaining = dest_size - len - 1;

    strncat(dest, extra, (size_t)remaining);
}

int labels_match(const char a[], const char b[])
{
    if (a == NULL || b == NULL)
    {
        return 0;
    }

    return strcmp(a, b) == 0 ? 1 : 0;
}

int find_text(const char label[], const char needle[])
{
    if (label == NULL || needle == NULL)
    {
        return -1;
    }

    const char *found = strstr(label, needle);

    if (found == NULL)
    {
        return -1;
    }

    return (int)(found - label);
}

