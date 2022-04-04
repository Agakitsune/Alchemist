/*
** EPITECH PROJECT, 2022
** lib
** File description:
** expand
*/

#include "buffer.h"

void expand(buffer_t *buffer, u64_t size)
{
    byte_t *save;

    if (!buffer)
        return;
    save = buffer->content;
    if ((buffer->size + size) < buffer->size) {
        return;
    }
    buffer->content = my_realloc(buffer->content, buffer->size + size + 1);
    if (buffer->content == NULL) {
        buffer->content = save;
        return;
    }
    set_memory(buffer->content + buffer->size, 0, size + 1);
    buffer->size += size;
}
