/*
** EPITECH PROJECT, 2022
** lib
** File description:
** get_value
*/

#include "astable.h"

const struct cmd VALUES[] =  {{"{", &get_object}, \
                                {"\"", &get_string}, \
                                {"[", &get_array}, \
                                {"-0123456789", &get_number}, \
                                {"tf", &get_bool}, \
                                {"n", &get_null}};

void json_move_to(buffer_t *buffer, size_t n)
{
    move_to(buffer, n);
    skip_whitespace(buffer);
}

bool get_value(json_t *data, buffer_t *buffer)
{
    skip_whitespace(buffer);
    for (size_t index = 0; index < 6; ++index) {
        if (my_strcspn((char *)(buffer->content + buffer->index), VALUES[index].flag) == 0) {
            if (VALUES[index].func != get_number && VALUES[index].func != get_bool && VALUES[index].func != get_null)
                move_to(buffer, 1);
            return VALUES[index].func(data, buffer);
        }
    }
    return false;
}
