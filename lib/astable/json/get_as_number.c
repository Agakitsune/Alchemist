/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** get_as_number
*/

#include "astable.h"

double get_as_number(json_t *json)
{
    if (!is_number(json))
        return 0.0;
    else
        return json->_data.number;
}
