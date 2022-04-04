/*
** EPITECH PROJECT, 2022
** lib
** File description:
** read_string
*/

#include "buffer.h"

char *read_string(buffer_t *buffer, unsigned long long n)
{
    byte_t *tmp = read_bytes(buffer, n);
    char *str = malloc(sizeof(byte_t) * (n + 1));

    copy_memory(str, tmp, n);
    str[n] = '\0';
    free(tmp);
    return str;
}
