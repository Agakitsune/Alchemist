/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_strsep
*/

#include "string.h"

char *my_strsep(char **str, const char *delim)
{
    char *begin;
    char *end;

    if (!str || !delim)
        return NULL;
    begin = *str;
    if (!begin)
        return NULL;
    end = begin + my_strcspn(begin, delim);
    if (*end) {
        *end++ = '\0';
        *str = end;
    } else {
        *str = NULL;
    }
    return begin;
}
