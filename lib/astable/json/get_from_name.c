/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** get
*/

#include "astable.h"

json_t *get_from_name(json_object_t *object, const char *name)
{
    json_entry_t *tmp;

    for (size_t i = 0; i < object->_size; i++) {
        tmp = &(object->_data[i]);
        if (my_strcmp(name, tmp->name) == 0)
            return &(tmp->_data);
    }
    return NULL;
}
