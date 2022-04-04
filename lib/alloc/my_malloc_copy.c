/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** my_malloc_copy
*/

#include "alloc.h"

void *my_malloc_copy(void *base)
{
    void *ptr = my_malloc(my_malloc_get_size(base));

    copy_memory(ptr, base, my_malloc_get_size(base));
    return ptr;
}
