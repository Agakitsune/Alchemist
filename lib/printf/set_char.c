/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-raphael.turpin
** File description:
** set_char
*/

#include "printf.h"

bool set_char(char **str, va_list ap)
{
    char c = va_arg(ap, int);
    unsigned long str_index = my_strlen(*str);

    if (!str)
        return false;
    *str = my_realloc(*str, my_strlen(*str) + 2);
    set_memory(*str + str_index, 0, 2);
    if (!(*str))
        return false;
    my_strcpy(*str + str_index, (char []){c, '\0'});
    return true;
}

bool set_char2(char **str, char c)
{
    unsigned long str_index = my_strlen(*str);

    if (!str)
        return false;
    *str = my_realloc(*str, my_strlen(*str) + 2);
    set_memory(*str + str_index, 0, 2);
    if (!(*str))
        return false;
    my_strcpy(*str + str_index, (char []){c, '\0'});
    return true;
}
