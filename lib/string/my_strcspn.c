/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_strcspn
*/

#include "string.h"

size_t my_strcspn(const char *str, const char *reject)
{
    const char *str_tmp = str;
    const char *reject_tmp = reject;
    size_t len = 0;

    if (!str || !reject)
        return 0;
    while (*str_tmp) {
        if (my_strchr(reject_tmp, *str_tmp) == NULL) {
            str_tmp++;
            len++;
            continue;
        }
        break;
    }
    return len;
}
