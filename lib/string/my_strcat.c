/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_strcat
*/

#include "string.h"

char *my_strcat(char *destination, const char *source)
{
    char *dest_tmp = destination;
    const char *src_tmp = source;

    if (!destination || !source)
        return NULL;
    dest_tmp += my_strlen(dest_tmp);
    while (*src_tmp) {
        *dest_tmp = *src_tmp;
        src_tmp++;
        dest_tmp++;
    }
    *dest_tmp = '\0';
    return dest_tmp;
}
