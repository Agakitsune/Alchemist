/*
** EPITECH PROJECT, 2022
** lib
** File description:
** search_memory
*/

#include "memory.h"

void *search_memory(const void *block, unsigned char chr, size_t n)
{
    unsigned char *tmp = (unsigned char *)(long long)block;

    if (!block)
        return NULL;
    while (n--) {
        if (*tmp == chr)
            return tmp;
        tmp++;
    }
    return NULL;
}
