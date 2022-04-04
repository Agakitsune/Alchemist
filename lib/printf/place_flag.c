/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-raphael.turpin
** File description:
** place_flag
*/

#include "printf.h"

bool place_flag(char **str, flag_t *flag, va_list ap)
{
    if (!str || !flag)
        return false;
    return flag->display_func(str, ap);
}
