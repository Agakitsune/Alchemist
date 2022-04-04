/*
** EPITECH PROJECT, 2022
** lib
** File description:
** dtor_buffer
*/

#include "buffer.h"

void dtor_buffer(buffer_t *buffer)
{
    my_free(buffer->content);
    my_free(buffer);
}
