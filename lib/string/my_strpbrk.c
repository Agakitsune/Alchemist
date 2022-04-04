/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_strpbrk
*/

#include "string.h"

char *my_strpbrk(const char *str, const char *accept)
{
    char *str_tmp = ((char *)(long long)str);
    const char *accept_tmp = accept;

    if (!str || !accept)
        return NULL;
    while (*str_tmp) {
        if (my_strchr(accept_tmp, *str_tmp) != NULL)
            return (char *)str_tmp;
        str_tmp++;
    }
    return NULL;
}
