#include "secure.h"
#include <string.h>

int safe_copy(char *dst, size_t dst_sz, const char *src)
{
    if (dst == NULL || src == NULL || dst_sz == 0)
        return -1;

    size_t len = strlen(src);

    if (len >= dst_sz) {
        memcpy(dst, src, dst_sz - 1);
        dst[dst_sz - 1] = '\0';
        return 1;
    }

    memcpy(dst, src, len + 1);
    return 0;
}

int safe_concat(char *dst, size_t dst_sz, const char *src)
{
    if (dst == NULL || src == NULL || dst_sz == 0)
        return -1;

    size_t dst_len = strnlen(dst, dst_sz);

    if (dst_len == dst_sz)
        return -1;

    size_t src_len = strlen(src);
    size_t available = dst_sz - dst_len - 1;

    if (src_len > available) {
        memcpy(dst + dst_len, src, available);
        dst[dst_sz - 1] = '\0';
        return 1;
    }

    memcpy(dst + dst_len, src, src_len + 1);
    return 0;
}
