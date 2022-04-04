/*
** EPITECH PROJECT, 2022
** Raycast
** File description:
** set_float
*/

#include "printf.h"

bool put_base(char **str, double f)
{
    long long tmp = (long long)f;

    return set_number_base(str, tmp, 10);
}

bool put_mantisse(char **str, double f)
{
    long long tmp = (long long)f;

    f = f - tmp;
    for (size_t i = 0; i < 6; i++) {
        f *= 10;
        tmp = (long long)f;
        if ((tmp % 10) == 0) {
            f /= 10;
            break;
        }
    }
    tmp = (long long)f;
    return set_number_base(str, tmp, 10);
}

bool set_float(char **str, va_list ap)
{
    double tmp = va_arg(ap, double);

    if (!str)
        return false;
    if (!put_base(str, tmp))
        return false;
    if (!set_char2(str, '.'))
        return false;
    if (!put_mantisse(str, tmp))
        return false;
    return true;
}
