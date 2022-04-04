/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_strlen
*/

#include "string.h"

size_t my_strlen(const char *str)
{
    const char *str_tmp = str;
    size_t len = 0;

    if (!str)
        return 0;
    while (*str_tmp++)
        len++;
    return len;
}
