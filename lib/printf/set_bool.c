/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-raphael.turpin
** File description:
** set_bool
*/

#include "printf.h"

bool set_bool(char **str, va_list ap)
{
    bool value = va_arg(ap, int);
    unsigned long str_index = my_strlen(*str);

    if (!str)
        return false;
    if (value) {
        *str = my_realloc(*str, my_strlen(*str) + 5);
        set_memory(*str + str_index, 0, 5);
    } else {
        *str = my_realloc(*str, my_strlen(*str) + 6);
        set_memory(*str + str_index, 0, 6);
    }
    if (!(*str))
        return false;
    if (value)
        my_strcpy(*str + str_index, "True");
    else
        my_strcpy(*str + str_index, "False");
    return true;
}
