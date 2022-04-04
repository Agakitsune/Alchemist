/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** sort
*/

#include "c++/set.h"

static int64_t partition(void *this, int64_t low, int64_t high)
{
    uint64_t size = set_data_size(this);
    char *ptr = this;
    void *pivot = ptr + high * size;
    int64_t i = (low - 1);

    for (int64_t j = low; j < high; j++) {
        if (set_cmp(this)(ptr + j * size, pivot) <= 0) {
            i++;
            set_swap(this, i, j);
        }
    }
    set_swap(this, i + 1, high);
    return (i + 1);
}

static void quick_sort(void *this, int64_t low, int64_t high)
{
    int64_t pivot = 0;

    if (low < high) {
        pivot = partition(this, low, high);
        quick_sort(this, low, pivot - 1);
        quick_sort(this, pivot + 1, high);
    }
}

void set_sort(void *this)
{
    int64_t len = set_last(this);

    if (!this)
        return;
    if (len < 1)
        return;
    quick_sort(this, 0, len);
}
