/*
** EPITECH PROJECT, 2022
** lib
** File description:
** open_file
*/

#include "buffer.h"

buffer_t *open_file(const char *filepath)
{
    buffer_t *buff = new_buffer(0);
    int fd = open(filepath, O_RDONLY);
    int char_read;
    char tmp[4096] = {0};

    if (fd == -1) {
        dtor_buffer(buff);
        return NULL;
    }
    while ((char_read = read(fd, tmp, 4096)) > 0) {
        push_bytes(buff, (byte_t *)tmp, char_read);
    }
    if (char_read == -1) {
        dtor_buffer(buff);
        return NULL;
    }
    return buff;
}
