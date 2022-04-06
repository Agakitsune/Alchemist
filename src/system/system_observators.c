/*
** EPITECH PROJECT, 2022
** Alchemist
** File description:
** system_observators
*/

#include "alchemist/system.h"

void *system_get_extra(system_t *this)
{
    char *ptr = (char *)this;

    if (!this || !this->has_extra)
        return NULL;
    return ptr + sizeof(system_t);
}
