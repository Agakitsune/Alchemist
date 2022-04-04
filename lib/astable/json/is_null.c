/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** is_null
*/

#include "astable.h"

bool is_null(json_t *json)
{
    return json->_type == NONE;
}
