/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** signature
*/

#include "string.h"

#include "alchemist/system.h"
#include "alchemist/world.h"

static char *tok(char *str, char **hold)
{
    char *tok = NULL;
    uint64_t size;

    str += my_strspn(str, " ,");
    size = my_strcspn(str, " ,");
    if (!size)
        return NULL;
    tok = my_strndup(str, size);
    if (!tok)
        return NULL;
    str += size;
    *hold = str;
    return tok;
}

bool system_set_signature(system_t *this, const char *str)
{
    char *tmp = (char *)(long)str;
    char *token = NULL;

    if (!this || !str)
        return false;
    while (true) {
        token = tok(tmp, &tmp);
        if (!token)
            break;
        this->signature |=
        get_component_signature(&get_world()->c_manager, fnv_hash_str(token));
        my_free(token);
    }
    return true;
}
