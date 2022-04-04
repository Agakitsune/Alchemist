/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-raphael.turpin
** File description:
** parse_flag
*/

#include "printf.h"
#include <stdio.h>

format_t FORMATS[] = {
    {"i", 1, &set_number},
    {"x", 1, &set_hex},
    {"B", 1, &set_byte},
    {"s", 1, &set_string},
    {"c", 1, &set_char},
    {"b", 1, &set_bool},
    {"p", 1, &set_ptr},
    {"f", 1, &set_float},
    {NULL, 0, NULL}
};

flag_t *read_flag(const char *str)
{
    flag_t *flag = my_calloc(1, sizeof(flag_t));

    if (!flag)
        return NULL;
    str++;
    for (long i = 0; (*str && *str != '}'); i++) {
        if (my_strncmp(str, FORMATS[i].flag, FORMATS[i].size) == 0) {
            flag->display_func = FORMATS[i].func;
            flag->size += FORMATS[i].size;
            str += FORMATS[i].size;
        }
        if (!FORMATS[i].flag) {
            my_free(flag);
            return NULL;
        }
    }
    if (!(*str)) {
        my_free(flag);
        return NULL;
    }
    return flag;
};
