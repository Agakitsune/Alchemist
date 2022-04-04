/*
** EPITECH PROJECT, 2022
** lib
** File description:
** read_bytes
*/

#include "buffer.h"

byte_t *read_bytes(buffer_t *buffer, u64_t n)
{
    byte_t *tmp;

    if (!buffer || !buffer->content)
        return NULL;
    tmp = malloc(sizeof(byte_t) * n);
    if (!tmp)
        return NULL;
    if (buffer->index + n > buffer->size) {
        n = buffer->size - buffer->index;
    }
    copy_memory(tmp, buffer->content + buffer->index, n);
    return tmp;
}
