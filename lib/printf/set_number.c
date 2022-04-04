/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-raphael.turpin
** File description:
** set
*/

#include "printf.h"

unsigned short get_number_size(long long number, unsigned int base)
{
    unsigned short size = 0;

    if (number == 0)
        return 1;
    while (number != 0) {
        size++;
        number /= base;
    }
    return size;
}

char get_char_at(long long number, unsigned short index, unsigned int base)
{
    unsigned short number_size = get_number_size(number, base);
    const char *chars = "0123456789abcdef";

    for (size_t i = index; i < (unsigned short)(number_size - 1); i++) {
        number /= base;
    }
    return chars[number % base];
}

bool set_number(char **str, va_list ap)
{
    long long number = va_arg(ap, long long);

    return set_number_base(str, number, 10);
}

bool set_hex(char **str, va_list ap)
{
    long long number = va_arg(ap, long long);

    return set_number_base(str, number, 16);
}

bool set_number_base(char **str, long long number, unsigned int base)
{
    unsigned short number_size = get_number_size(number, base);
    unsigned long str_index = my_strlen(*str);

    if (!str)
        return false;
    *str = my_realloc(*str, my_strlen(*str) + number_size + 1);
    set_memory(*str + str_index, 0, number_size + 1);
    if (!(*str))
        return false;
    for (size_t i = 0; i < number_size; i++) {
        (*str)[str_index + i] = get_char_at(number, i, base);
    }
    return true;
}
