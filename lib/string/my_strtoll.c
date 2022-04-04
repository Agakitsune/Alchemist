/*
** EPITECH PROJECT, 2021
** my_strtoll
** File description:
** my strtoll
*/

#include <stdbool.h>

#include "alloc.h"

bool is_digit(char c)
{
    return ('0' <= c && c <= '9');
}

int64_t my_strtoll(const char *nptr, char **endptr)
{
    char sign = 1;
    int64_t result = 0;
    char *tmp = (char *)(ptrdiff_t)nptr;

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
