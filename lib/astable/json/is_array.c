/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** is_array
*/

#include "astable.h"

bool is_array(json_t *json)
{
    return json->_type == ARRAY;
}
