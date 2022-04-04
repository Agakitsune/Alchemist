/*
** EPITECH PROJECT, 2022
** lib
** File description:
** insert_bytes
*/

#include "buffer.h"
#include <stdio.h>

void insert_bytes(buffer_t *buffer, byte_t *stream, u64_t s_size, u64_t pos)
{
    u64_t old_size;

    if (!buffer || !stream)
        return;
    old_size = buffer->size;
    expand(buffer, s_size);
    if (buffer->size == old_size) {
        return;
    }
    move_memory(buffer->content + pos + s_size, buffer->content + pos,
    old_size - pos);
    copy_memory(buffer->content + pos, stream, s_size);
}
