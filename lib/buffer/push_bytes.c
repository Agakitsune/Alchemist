/*
** EPITECH PROJECT, 2022
** lib
** File description:
** push_bytes
*/

#include "buffer.h"

void push_bytes(buffer_t *buffer, byte_t *stream, u64_t s_size)
{
    u64_t old_size = buffer->size;

    expand(buffer, s_size);
    if (buffer->size == old_size) {
        return;
    }
    copy_memory(buffer->content + old_size, stream, s_size);
}
