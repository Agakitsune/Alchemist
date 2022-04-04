/*
** EPITECH PROJECT, 2022
** lib
** File description:
** read_number
*/

#include "buffer.h"

long long read_number(buffer_t *buffer, u64_t size, byte_order_t byte_order)
{
    bool negative = *(buffer->content + buffer->index) == '-';
    long long value = 0;
    byte_t *tmp;

    if (my_strcspn((const char *)read_bytes(buffer, 1), "+-") == 0)
        move_to(buffer, 1);
    tmp = read_bytes(buffer, size);
    if (byte_order == MY_BIG_ENDIAN) {
        while (size--) {
            value <<= 8;
            value += *tmp;
            ++tmp;
        }
    } else if (byte_order == MY_LITTLE_ENDIAN) {
        while (size--) {
            value += *tmp << (size * 8);
            ++tmp;
        }
    }
    return value * (1 + (-2 * negative));
}
