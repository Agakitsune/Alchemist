/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_strtok_r
*/

#include "string.h"

char *fix(char *str, char **old)
{
    if (!str)
        str = *old;
    return str;
}

char *my_strtok_r(char *str, const char *delim, char **old)
{
    char *end;

    str = fix(str, old);
    if (!(*str)) {
        *old = str;
        return NULL;
    }
    str += my_strspn(str, delim);
    if (!(*str)) {
        *old = str;
        return NULL;
    }
    end = str + my_strcspn(str, delim);
    if (!(*end)) {
        *old = end;
        return str;
    }
    *end = '\0';
    *old = end + 1;
    return str;
}
