/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_strdup
*/

#include "string.h"

char *my_strdup(const char *str)
{
    char *res = my_malloc(my_strlen(str) + 1);

    if (!str || !res)
        return NULL;
    my_strcpy(res, str);
    return res;
}
