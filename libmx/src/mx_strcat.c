#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int size1 = mx_strlen(s1);
    int size2 = mx_strlen(s2);
    
    for (int i = 0; i <= size2; i++)
        s1[size1 + i] = s2[i];
    return s1;
}

