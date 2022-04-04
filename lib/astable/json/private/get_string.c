/*
** EPITECH PROJECT, 2022
** lib
** File description:
** get_string
*/

#include "astable.h"

bool get_string(json_t *json, buffer_t *buffer)
{
    u64_t length = 0;

    length = my_strcspn((const char *)(buffer->content + buffer->index), "\"");
    json->_type = STRING;
    json->_data.string = read_string(buffer, length);
    json_move_to(buffer, length);
    if (*(buffer->content + buffer->index) != '"') {
        return false;
    }
    json_move_to(buffer, 1);
    return true;
}
