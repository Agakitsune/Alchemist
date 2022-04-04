/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_strndup
*/

#include "string.h"

char *my_strndup(const char *str, size_t n)
{
    char *res = my_malloc(n + 1);

    if (!str || !res) {
        free(res);
        return NULL;
    }
    my_strncpy(res, str, n);
    return res;
}
