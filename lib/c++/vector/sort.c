/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** sort
*/

#include "c++/vector.h"

static int64_t partition(void *this,
                        int64_t low,
                        int64_t high,
                        int64_t (*cmp)(void *a, void *b))
{
    char *ptr = this;
    void *pivot = ptr + high * vector_data_size(this);
    int64_t i = (low - 1);

    for (int64_t j = low; j < high; j++) {
        if (cmp(ptr + j * vector_data_size(this), pivot) <= 0) {
            i++;
            vector_swap(this, i, j);
        }
    }
    vector_swap(this, i + 1, high);
    return (i + 1);
}

static void quick_sort(void *this,
                        int64_t low,
                        int64_t high,
                        int64_t (*cmp)(void *a, void *b))
{
    int64_t pivot = 0;

    if (low < high) {
        pivot = partition(this, low, high, cmp);
        quick_sort(this, low, pivot - 1, cmp);
        quick_sort(this, pivot + 1, high, cmp);
    }
}

void vector_sort(void *this, int64_t (*cmp)(void *a, void *b))
{
    int64_t len = vector_back_index(this);

    if (!this || !cmp)
        return;
    if (len < 1)
        return;
    quick_sort(this, 0, len, cmp);
}
