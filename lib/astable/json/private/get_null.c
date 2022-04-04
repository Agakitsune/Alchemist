/*
** EPITECH PROJECT, 2022
** lib
** File description:
** get_null
*/

#include "astable.h"

bool get_null(json_t *json, buffer_t *buffer)
{
    if (my_strcmp(read_string(buffer, 4), "null") == 0) {
        json->_type = NONE;
        json->_data.null = NULL;
        json_move_to(buffer, 4);
        return true;
    }
    return false;
}
