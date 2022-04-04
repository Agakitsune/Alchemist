/*
** EPITECH PROJECT, 2022
** lib
** File description:
** retract
*/

#include "buffer.h"

void retract(buffer_t *buffer, u64_t size)
{
    byte_t *save = buffer->content;

    if ((buffer->size - size) > buffer->size) {
        return;
    }
    buffer->content = my_realloc(buffer->content, buffer->size - size + 1);
    if (buffer->content == NULL) {
        buffer->content = save;
        return;
    }
    buffer->size -= size;
    buffer->content[buffer->size] = '\0';
}
