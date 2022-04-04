/*
** EPITECH PROJECT, 2022
** lib
** File description:
** read_ptr
*/

#include "buffer.h"

void *read_ptr(buffer_t *buffer)
{
    u64_t ptr = read_number(buffer, 8, MY_BIG_ENDIAN);

    return ((void *)ptr);
}
