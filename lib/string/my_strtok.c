/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_strtok
*/

#include "string.h"

char *my_strtok(char *str, const char *delim)
{
    static char *olds;
    return my_strtok_r(str, delim, &olds);
}
