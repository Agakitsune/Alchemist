/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_strncpy
*/

#include "string.h"

char *my_strncpy(char *destination, const char *source, size_t n)
{
    char *dest_tmp = destination;
    const char *src_tmp = source;

    if (!destination || !source)
        return NULL;
    while (*src_tmp && n--) {
        *dest_tmp++ = *src_tmp;
        src_tmp++;
    }
    *dest_tmp = '\0';
    return dest_tmp;
}
