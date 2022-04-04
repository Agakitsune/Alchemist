/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** is_string
*/

#include "astable.h"

bool is_string(json_t *json)
{
    return json->_type == STRING;
}
