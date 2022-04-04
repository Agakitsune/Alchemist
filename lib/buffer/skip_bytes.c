/*
** EPITECH PROJECT, 2022
** lib
** File description:
** skip_bytes
*/

#include "buffer.h"

void skip_bytes(buffer_t *buffer, u64_t n)
{
    move_to(buffer, n);
}
