/*
** EPITECH PROJECT, 2022
** lib
** File description:
** set_memory
*/

#include "memory.h"

void *set_memory(void *src, unsigned char data, size_t n)
{
    char *tmp = src;

    while (n--)
        *tmp++ = data;
    return tmp;
}
