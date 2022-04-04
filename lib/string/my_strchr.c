/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_strchr
*/

#include "string.h"

char *my_strchr(const char *str, char chr)
{
    char *str_tmp = (char *)(long long)str;

    if (!str)
        return NULL;
    while (*str_tmp) {
        if (*str_tmp == chr)
            return (char *)str_tmp;
        str_tmp++;
    }
    return NULL;
}
