/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** get_as_array
*/

#include "astable.h"

json_array_t *get_as_array(json_t *json)
{
    if (!is_array(json))
        return NULL;
    else
        return json->_data.array;
}