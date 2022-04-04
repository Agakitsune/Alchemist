/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-raphael.turpin
** File description:
** set_string
*/

#include "printf.h"

bool set_string(char **str, va_list ap)
{
    char *string = va_arg(ap, char *);
    size_t string_size = my_strlen(string);
    unsigned long str_index = my_strlen(*str);

    if (!str)
        return false;
    *str = my_realloc(*str, my_strlen(*str) + string_size + 1);
    set_memory(*str + str_index, 0, string_size + 1);
    if (!(*str))
        return false;
    my_strcpy(*str + str_index, string);
    return true;
}
