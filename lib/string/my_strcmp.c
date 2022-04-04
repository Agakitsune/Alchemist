/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_strcmp
*/

#include "string.h"

int my_strcmp(const char *str1, const char *str2)
{
    const unsigned char *tmp1 = (const unsigned char *)str1;
    const unsigned char *tmp2 = (const unsigned char *)str2;

    if (!str1 && !str2)
        return 0;
    else if (!str1)
        return 0 - *str2;
    else if (!str2)
        return *str1 - 0;
    while (*tmp1 == *tmp2) {
        if (!(*tmp1) && !(*tmp2))
            break;
        tmp1++;
        tmp2++;
    }
    return *tmp1 - *tmp2;
}
