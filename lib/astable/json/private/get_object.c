/*
** EPITECH PROJECT, 2022
** lib
** File description:
** get_object
*/

#include "astable.h"

bool append_entry(json_object_t *object, json_entry_t *value)
{
    object->_size++;
    object->_data = my_realloc(object->_data, \
    sizeof(json_entry_t) * object->_size);

    if (!object->_data)
        return false;
    object->_data[object->_size - 1] = *value;
    free(value);
    return true;
}

json_entry_t *get_entry(buffer_t *buffer)
{
    u64_t length = 0;
    json_entry_t *entry = malloc(sizeof(json_entry_t));

    skip_whitespace(buffer);
    if (*(buffer->content + buffer->index) == '"')
        move_to(buffer, 1);
    length = my_strcspn((const char *)(buffer->content + buffer->index), "\"");
    entry->name = read_string(buffer, length);
    json_move_to(buffer, length + 1);
    if (*(buffer->content + buffer->index) != ':')
        return NULL;
    json_move_to(buffer, 1);
    if (get_value(&entry->_data, buffer) == false)
        return NULL; // TODO dtor JSON
    return entry;
}

bool get_object(json_t *json, buffer_t *buffer)
{
    json_entry_t *entry = NULL;
    json_object_t *object = my_calloc(1, sizeof(json_object_t));

    object->_data = my_malloc(0);
    while (*(buffer->content + buffer->index) != '}') {
        if (*(buffer->content + buffer->index) == ',')
            json_move_to(buffer, 1);
        entry = get_entry(buffer);
        if (entry == NULL)
            return false; // TODO Free entry
        if (append_entry(object, entry) == false)
            return false; // TODO Free entry
        skip_whitespace(buffer);
    }
    json_move_to(buffer, 1);
    json->_type = OBJECT;
    json->_data.object = object;
    return true;
}
