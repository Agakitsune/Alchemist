/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** get_from_index
*/

#include "astable.h"

json_t *get_from_index(json_array_t *array, size_t index)
{
    if (array->_size <= index)
        return NULL;
    return &(array->_data[index]);
}
