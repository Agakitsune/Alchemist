/*
** EPITECH PROJECT, 2022
** lib
** File description:
** copy_memory
*/

#include "memory.h"
#include <stdio.h>

void *copy_memory(void *dest, const void *src, size_t n)
{
    char *dest_tmp = dest;
    const char *src_tmp = src;

    if (!dest || !src)
        return NULL;
    while (n--)
        *dest_tmp++ = *src_tmp++;
    return dest_tmp;
}
