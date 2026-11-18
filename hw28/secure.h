#ifndef SECURE_H
#define SECURE_H

#include <stddef.h>

int safe_copy(char *dst, size_t dst_sz, const char *src);

int safe_concat(char *dst, size_t dst_sz, const char *src);

#endif
