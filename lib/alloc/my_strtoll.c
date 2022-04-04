/*
** EPITECH PROJECT, 2021
** my_strtoll
** File description:
** my strtoll
*/

#include "alloc.h"

int is_digit(char c)
{
    return ('0' <= c && c <= '9');
}

long long my_strtoll(const char *nptr, char **endptr)
{
    char sign = 1;
    long long result = 0;
    char *tmp = (char *)(long long)nptr;

    if (nptr == NULL) {
        *endptr = NULL;
        return 0;
    }
    while ((*tmp == '-') || (*tmp == '+')) {
        if (*tmp == '-')
            sign *= -1;
        tmp++;
    }
    while (is_digit(*tmp)) {
        result *= 10;
        result += *tmp - 48;
        tmp++;
    }
    *endptr = tmp;
    return result * sign;
}
