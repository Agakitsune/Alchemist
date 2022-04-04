/*
** EPITECH PROJECT, 2022
** lib
** File description:
** read_at
*/

#include "buffer.h"

byte_t *read_at(buffer_t *buffer, u64_t pos, u64_t n)
{
    u64_t old_pos = buffer->index;
    byte_t *tmp;

    go_to(buffer, pos);
    tmp = read_bytes(buffer, n);
    go_to(buffer, old_pos);
    return tmp;
}
