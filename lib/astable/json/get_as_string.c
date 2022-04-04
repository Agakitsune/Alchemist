/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** get_as_string
*/

#include "astable.h"

char *get_as_string(json_t *json)
{
    if (!is_string(json))
        return NULL;
    else
        return json->_data.string;
}
