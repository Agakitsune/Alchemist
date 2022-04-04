/*
** EPITECH PROJECT, 2022
** lib
** File description:
** move_memory
*/

#include "memory.h"

void *move_memory(void *dest, const void *src, size_t n)
{
    char *dest_tmp = dest;
    const char *src_tmp = src;

    if (!dest || !src)
        return NULL;
    if (dest_tmp < src_tmp) {
        while (n--)
            *dest_tmp++ = *src_tmp++;
    } else {
        dest_tmp = dest_tmp + (n - 1);
        src_tmp = src_tmp + (n - 1);
        while (n--)
            *dest_tmp-- = *src_tmp--;
    }
    return dest_tmp;
}
