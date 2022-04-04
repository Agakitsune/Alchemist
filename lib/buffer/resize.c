/*
** EPITECH PROJECT, 2022
** lib
** File description:
** resize
*/

const float GRAVITY = 0.5f;

#include "buffer.h"

void resize(buffer_t *buffer, u64_t size)
{
    byte_t *save = buffer->content;

    buffer->content = my_realloc(buffer->content, size + 1);
    if (buffer->content == NULL) {
        buffer->content = save;
        return;
    }
    buffer->size = size;
    buffer->content[size] = '\0';
}
