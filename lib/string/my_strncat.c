/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_strncat
*/

#include "string.h"

char *my_strncat(char *destination, const char *source, size_t n)
{
    char *dest_tmp = destination;
    const char *src_tmp = source;

    if (!destination || !source)
        return NULL;
    dest_tmp += my_strlen(dest_tmp);
    while (n--) {
        if (!*src_tmp)
            break;
        *dest_tmp++ = *src_tmp++;
    }
    *dest_tmp = '\0';
    return dest_tmp;
}
