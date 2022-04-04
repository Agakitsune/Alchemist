/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-raphael.turpin
** File description:
** vprintf
*/

#include "printf.h"

ssize_t buffered_write(int fd, const char *str)
{
    size_t len = my_strlen(str);
    ssize_t char_writen = 0;
    ssize_t tmp = 0;

    while (len > 8192) {
        tmp = write(fd, str, 8192);
        if (tmp == -1)
            return -1;
        char_writen += tmp;
        len -= 8192;
        str += 8192;
    }
    tmp = write(fd, str, len);
    if (tmp == -1)
        return -1;
    return char_writen + tmp;
}

int my_vprintf(const char *format, va_list ap)
{
    return my_vdprintf(1, format, ap);
}

int my_vdprintf(int fd, const char *format, va_list ap)
{
    char *buff = my_vsaprintf(format, ap);
    ssize_t char_writen = buffered_write(fd, buff);

    my_free(buff);
    return char_writen;
}

int free_on_error(bool error, flag_t *flag, char *buff)
{
    if (error) {
        my_free(flag);
        my_free(buff);
    }
    return 1;
}

char *my_vsaprintf(const char *format, va_list ap)
{
    char *buff = NULL;
    flag_t *flag = NULL;
    bool error = false;

    for (; *format; format++) {
        if (*format == '{') {
            if (((flag = read_flag(format)) == NULL) && (error = true))
                break;
            if (!place_flag(&buff, flag, ap) && (error = true))
                break;
            format += flag->size + 1;
            my_free(flag);
            continue;
        }
        if (!set_char2(&buff, *format) && (error = true))
            break;
    }
    if (error && free_on_error(error, flag, buff))
        return NULL;
    return buff;
}
