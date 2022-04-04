/*
** EPITECH PROJECT, 2021
** my_malloc_get_size
** File description:
** my_malloc_get_size
*/

#include "alloc.h"

size_t my_malloc_get_size(void *ptr)
{
    if (ptr == NULL)
        return 0;
    return my_malloc_get_header(ptr)->size;
}
