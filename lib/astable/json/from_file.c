/*
** EPITECH PROJECT, 2022
** lib
** File description:
** from_file
*/

#include "astable.h"

void skip_whitespace(buffer_t *buffer)
{
    move_to(buffer, my_strspn((const char *)(buffer->content + buffer->index), " \n\t"));
}

bool from_file(json_t *json, const char *filepath)
{
    buffer_t *buffer = open_file(filepath);

    if (buffer == NULL)
        return false;
    skip_whitespace(buffer);
    return get_value(json, buffer);
}
