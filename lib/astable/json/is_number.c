/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** is_number
*/

#include "astable.h"

bool is_number(json_t *json)
{
    return json->_type == NUMBER;
}
