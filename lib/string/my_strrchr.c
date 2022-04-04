/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_strrchr
*/

#include "string.h"

char *my_strrchr(const char *str, char chr)
{
    size_t len = my_strlen(str);
    char *str_tmp = (char *)(long long)(str + (len - 1));

    if (!str)
        return NULL;
    while (len--) {
        if (*str_tmp == chr)
            return str_tmp;
        str_tmp--;
    }
    return NULL;
}
