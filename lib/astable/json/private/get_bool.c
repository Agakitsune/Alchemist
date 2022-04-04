/*
** EPITECH PROJECT, 2022
** lib
** File description:
** get_bool
*/

#include "astable.h"

bool get_bool(json_t *json, buffer_t *buffer)
{
    if (my_strncmp((char *)(buffer->content + buffer->index),
        "true", 4) == 0) {
        json->_type = BOOLEAN;
        json->_data.boolean = true;
        json_move_to(buffer, 4);
        return true;
    } else if (my_strncmp((char *)(buffer->content + buffer->index),
        "false", 5) == 0) {
        json->_type = BOOLEAN;
        json->_data.boolean = false;
        json_move_to(buffer, 5);
        return true;
    }
    return false;
}
