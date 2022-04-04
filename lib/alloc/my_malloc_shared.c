/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** my_malloc_shared
*/

#include "alloc.h"

void *my_malloc_shared(void *ptr)
{
    if (!ptr)
        return NULL;
    my_malloc_get_header(ptr)->rc++;
    return ptr;
}
