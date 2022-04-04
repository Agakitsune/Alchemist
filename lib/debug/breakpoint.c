/*
** EPITECH PROJECT, 2022
** Raycast
** File description:
** breakpoint
*/

#include "debug.h"

void _breakpoint(const char *str)
{
    char useless[256];
    char *tmp = (char *)(long)str;

    flog(DEBUG, str);
    while (1) {
        if (read(0, &useless, 256) != -1)
            break;
    }
    my_free(tmp);
}
