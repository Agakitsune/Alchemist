/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_strspn
*/

#include "string.h"

size_t my_strspn(const char *str, const char *accept)
{
    const char *str_tmp = str;
    const char *accept_tmp = accept;
    size_t len = 0;

    if (!str || !accept)
        return 0;
    while (*str_tmp) {
        if (my_strchr(accept_tmp, *str_tmp) != NULL) {
            str_tmp++;
            len++;
            continue;
        }
        break;
    }
    return len;
}
