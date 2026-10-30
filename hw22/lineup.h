#ifndef LINEUP_H
#define LINEUP_H

void print_label(const char label[]);
int label_len(const char label[]);
void safe_copy(char dest[], int dest_size, const char src[]);
void safe_join(char dest[], int dest_size, const char extra[]);
int labels_match(const char a[], const char b[]);
int find_text(const char label[], const char needle[]);

#endif
