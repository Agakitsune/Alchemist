/*
** EPITECH PROJECT, 2022
** lib
** File description:
** get_number
*/

#include "astable.h"

double my_pow(u64_t value, long long exponent)
{
    double result = 1;
    if (exponent > 0) {
        while (exponent--)
            result *= value;
    } else if (exponent < 0) {
        while (exponent++)
            result /= value;
    }
    return result;
}

bool get_number(json_t *json, buffer_t *buffer)
{
    u64_t length = 0;
    double result = 0;
    double fraction = 0;
    long long exponent = 0;
    char *useless;

    result = my_strtoll((const char *)(buffer->content + buffer->index), &useless);
    length = (u64_t)useless - (u64_t)(buffer->content + buffer->index);
    json_move_to(buffer, length);
    if (my_strcspn((char *)(buffer->content + buffer->index), ".") == 0) {
        json_move_to(buffer, 1);
        fraction = my_strtoll((const char *)(buffer->content + buffer->index), &useless);
        length = (u64_t)useless - (u64_t)(buffer->content + buffer->index);
        fraction *= my_pow(10, -length);
        json_move_to(buffer, length);
    }
    if (my_strcspn((char *)(buffer->content + buffer->index), "eE") == 0) {
        json_move_to(buffer, 1);
        exponent = my_strtoll((const char *)(buffer->content + buffer->index), &useless);
        length = (u64_t)useless - (u64_t)(buffer->content + buffer->index);
        json_move_to(buffer, length);
    }
    json->_type = NUMBER;
    json->_data.number = (result + fraction) * my_pow(10, exponent);
    return true;
}
