/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** is_object
*/

#include "astable.h"

bool is_object(json_t *json)
{
    return json->_type == OBJECT;
}
