/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** get_as_boolean
*/

#include "astable.h"

bool get_as_boolean(json_t *json)
{
    if (!is_boolean(json))
        return false;
    else
        return json->_data.boolean;
}
