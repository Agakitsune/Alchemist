/*
** EPITECH PROJECT, 2022
** Raycast
** File description:
** flag
*/

#include "debug.h"

void _flag(const char *str)
{
    char *tmp = (char *)(long)str;

    flog(DEBUG, str);
    my_free(tmp);
}