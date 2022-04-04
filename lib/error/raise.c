/*
** EPITECH PROJECT, 2022
** assets
** File description:
** raise
*/

#include "error.h"

int raise(int code, const char *message)
{
    if (message)
        my_dprintf(2, "{s}\n", message);
    garbage_collector();
    my_exit(code);
    return code;
}
