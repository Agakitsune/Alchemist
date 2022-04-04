/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** get_as_object
*/

#include "astable.h"

json_object_t *get_as_object(json_t *json)
{
    if (!is_object(json))
        return NULL;
    else
        return json->_data.object;
}
