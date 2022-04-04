/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** get_as_null
*/

#include "astable.h"

void *get_as_null(json_t *json)
{
    if (!is_null(json))
        return NULL;
    else
        return json->_data.null;
}
