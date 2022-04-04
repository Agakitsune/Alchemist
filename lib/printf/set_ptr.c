/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-raphael.turpin
** File description:
** set_ptr
*/

#include "printf.h"

unsigned short get_hex_size(long long number)
{
    unsigned short size = 0;

    if (number == 0)
        return 1;
    while (number != 0) {
        size++;
        number /= 16;
    }
    return size;
}

char get_hexchar_at(long long number, unsigned short index)
{
    unsigned short number_size = get_hex_size(number);
    const char *base = "0123456789abcdef";

    for (size_t i = index; i < (unsigned short)(number_size - 1); i++) {
        number /= 16;
    }
    return base[number % 16];
}

bool set_ptr(char **str, va_list ap)
{
    long long ptr = (long long)(va_arg(ap, void *));
    unsigned long str_index = my_strlen(*str);
    unsigned short number_size = get_hex_size(ptr);

    if (!str)
        return false;
    *str = my_realloc(*str, my_strlen(*str) + 2 + number_size + 1);
    set_memory(*str + str_index, 0, number_size + 1);
    if (!(*str))
        return false;
    my_strcpy(*str + str_index, "0x");
    set_number_base(str, ptr, 16);
    return true;
}
