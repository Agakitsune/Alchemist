/*
** EPITECH PROJECT, 2021
** my_malloc
** File description:
** my_malloc
*/

#include <stdio.h>
#include "alloc.h"

void *my_malloc(size_t n)
{
    uint8_t *ptr = malloc(sizeof(malloc_header_t) + n);
    malloc_header_t *tmp = (malloc_header_t *)ptr;

    if (ptr == NULL)
        return NULL;
    tmp->ptr = ptr + sizeof(malloc_header_t);
    tmp->size = n;
    tmp->rc = 1;
    add_to_garbage(tmp->ptr);
    return tmp->ptr;
}
