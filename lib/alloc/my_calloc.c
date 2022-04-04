/*
** EPITECH PROJECT, 2021
** my_calloc
** File description:
** my calloc
*/

#include <stdio.h>
#include "alloc.h"

void *my_calloc(size_t nmemb, size_t size)
{
    const size_t final_size = nmemb * size;
    void *tmp = my_malloc(final_size);

    if (tmp != NULL)
        set_memory(tmp, 0, final_size);
    return tmp;
}
