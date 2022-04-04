/*
** EPITECH PROJECT, 2022
** lib
** File description:
** new_buffer
*/

#include "buffer.h"

buffer_t *new_buffer(u64_t size)
{
    buffer_t *buff = my_calloc(1, sizeof(buffer_t));

    if (!buff)
        return NULL;
    buff->content = my_malloc(sizeof(byte_t) * (size + 1));
    buff->size = size;
    buff->content[size] = '\0';
    return buff;
}
