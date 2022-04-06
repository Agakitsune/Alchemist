/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** constructors
*/

#include "alchemist/system.h"

system_t *system_ctor(void (*func)(entity_t *entity),
                    void *extra,
                    size_t extra_size)
{
    system_t *this = my_malloc(sizeof(system_t) + extra_size);
    char *ptr = ((char *)this) + sizeof(system_t);

    if (!this || !func)
        return my_free(this), NULL;
    this->entities = SET_NEW(65536, entity_t, &entity_cmp_id);
    if (!this->entities)
        return my_free(this), NULL;
    this->signature = 0;
    this->system = func;
    this->has_extra = false;
    if (extra) {
        copy_memory(ptr, extra, extra_size);
        this->has_extra = true;
    }
    return this;
}

void system_dtor(system_t *this)
{
    if (!this)
        return;
    SET_DESTROY(this->entities);
    my_free(this);
}
