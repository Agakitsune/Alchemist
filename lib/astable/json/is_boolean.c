/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** is_boolean
*/

#include "astable.h"

bool is_boolean(json_t *json)
{
    return json->_type == BOOLEAN;
}
