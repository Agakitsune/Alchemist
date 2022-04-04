/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-raphael.turpin
** File description:
** printf
*/

#include "printf.h"

int my_printf(const char *format, ...)
{
    va_list ap;
    int char_writen = 0;

    va_start(ap, format);
    char_writen = my_vprintf(format, ap);
    va_end(ap);
    return char_writen;
}

int my_dprintf(int fd, const char *format, ...)
{
    va_list ap;
    int char_writen = 0;

    va_start(ap, format);
    char_writen = my_vdprintf(fd, format, ap);
    va_end(ap);
    return char_writen;
}

char *my_saprintf(const char *format, ...)
{
    va_list ap;
    char *buff = NULL;

    va_start(ap, format);
    buff = my_vsaprintf(format, ap);
    va_end(ap);
    return buff;
}
