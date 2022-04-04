/*
** EPITECH PROJECT, 2022
** lib
** File description:
** get_array
*/

#include "astable.h"

bool append(json_array_t *array, json_t *value)
{
    array->_size++;
    array->_data = my_realloc(array->_data,
        sizeof(json_t) * array->_size);
    if (!array->_data)
        return false;
    array->_data[array->_size - 1] = *value;
    return true;
}

bool get_array(json_t *json, buffer_t *buffer)
{
    json_t value = {0};
    json_array_t *array = my_calloc(1, sizeof(json_array_t));

    array->_data = my_malloc(0);
    while (*(buffer->content + buffer->index) != ']') {
        if (*(buffer->content + buffer->index) == ',')
            json_move_to(buffer, 1);
        skip_whitespace(buffer);
        if (get_value(&value, buffer) == false)
            return false; // TODO: dtor json of get_array
        append(array, &value);
        skip_whitespace(buffer);
    }
    json_move_to(buffer, 1);
    json->_type = ARRAY;
    json->_data.array = array;
    return true;
}
