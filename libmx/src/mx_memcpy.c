#include "../inc/libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    char *d = dst;
    const char *s = src;

    while (n--)
        *d++ = *s++;
    return dst;
}

