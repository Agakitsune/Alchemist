/*
** EPITECH PROJECT, 2022
** lib
** File description:
** compare_memory
*/

#include "memory.h"
#include <stdio.h>

int compare_memory(const void *ptr1, const void *ptr2, size_t n)
{
    const char *tmp1 = ptr1;
    const char *tmp2 = ptr2;

    if (!ptr1 && !ptr2)
        return 0;
    if (!ptr1) {
        return 0 - *tmp2;
    }
    if (!ptr2) {
        return *tmp1;
    }
    while (n--) {
        if (*tmp1 != *tmp2)
            return *tmp1 - *tmp2;
        ++tmp1;
        ++tmp2;
    }
    return 0;
}
