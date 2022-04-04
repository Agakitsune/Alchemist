/*
** EPITECH PROJECT, 2021
** my_realloc
** File description:
** my_realloc
*/

#include <stdio.h>
#include "alloc.h"

void *my_realloc(void *ptr, size_t size)
{
    void *tmp = NULL;

    if (ptr == NULL) {
        return my_malloc(size);
    } else if (size == 0) {
        my_free(ptr);
        return NULL;
    }
    if (my_malloc_get_size(ptr) > size)
        return ptr;
    tmp = my_malloc(size);
    if (tmp == NULL) {
        return NULL;
    }
    copy_memory(tmp, ptr, my_malloc_get_size(ptr));
    my_free(ptr);
    return tmp;
}
