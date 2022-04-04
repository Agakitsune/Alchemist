/*
** EPITECH PROJECT, 2022
** lib
** File description:
** move_to
*/

#include "buffer.h"

void move_to(buffer_t *buffer, long long n)
{
    if (buffer->index + n >= buffer->size)
        return;
    buffer->index += n;
}
