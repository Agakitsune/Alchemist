/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_strstr
*/

#include "string.h"

char *my_strstr(const char *str, const char *search_str)
{
    char *str_tmp = ((char *)(long long)str);
    char tmp[1] = {0};
    const char *search_tmp = search_str;

    if (!str || !search_str)
        return NULL;
    while (*str_tmp) {
        tmp[0] = search_tmp[0];
        str_tmp += my_strcspn(str_tmp, tmp);
        if (!(*str_tmp))
            break;
        if (my_strncmp(str_tmp, search_tmp, my_strlen(search_tmp)) == 0)
            return (char *)str_tmp;
        else
            str_tmp++;
    }
    return NULL;
}
