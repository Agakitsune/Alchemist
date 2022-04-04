/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** utils
*/

#include "alchemist/component_manager.h"

component_array_t *get_component_array(component_manager_t *this,
                                                hash_t component)
{
    bool found = false;
    uint64_t index = 0;

    for (; index < VECTOR_SIZE(this->component_hash); index++) {
        if (this->component_hash[index] == component) {
            found = true;
            break;
        }
    }
    if (!found)
        return NULL;
    return ARRAY_GET(this->component_data, index);
}

signature_t get_component_signature(component_manager_t *this,
                                        hash_t component)
{
    bool found = false;
    uint64_t index = 0;
    signature_t c_signature = 0;

    for (; index < VECTOR_SIZE(this->component_hash); index++) {
        if (this->component_hash[index] == component) {
            found = true;
            break;
        }
    }
    if (!found)
        return -1;
    BITSET_SET(&c_signature, index, true);
    return c_signature;
}
