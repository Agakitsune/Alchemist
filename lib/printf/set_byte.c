/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** set_byte
*/

#include "printf.h"

bool set_byte(char **str, va_list ap)
{
    unsigned char number = va_arg(ap, int);

    return set_number_base(str, number, 16);
}
