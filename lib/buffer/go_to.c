/*
** EPITECH PROJECT, 2022
** lib
** File description:
** go_to
*/

#include "buffer.h"

void go_to(buffer_t *buffer, u64_t pos)
{
    if (!buffer)
        return;
    if (pos >= buffer->size)
        return;
    buffer->index = pos;
}
