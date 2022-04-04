/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-raphael.turpin
** File description:
** printf
*/

#ifndef PRINTF_H_
    #define PRINTF_H_

    #include <stdarg.h>
    #include <unistd.h>
    #include <stddef.h>
    #include <stdbool.h>
    #include <stdio.h>

    #include "alloc.h"
    #include "string.h"
    #include "memory.h"

typedef struct flag flag_t;
typedef struct format format_t;
typedef enum cast cast_t;

enum cast {
    CHAR,
    SHORT,
    INT,
    LONG,
    LLONG
};

struct flag {
    size_t size;
    bool (*display_func)(char **str, va_list ap);
};

struct format {
    char *flag;
    size_t size;
    bool (*func)(char **str, va_list ap);
};

flag_t *read_flag(const char *str);
bool place_flag(char **str, flag_t *flag, va_list ap);

bool set_number(char **str, va_list ap);
bool set_hex(char **str, va_list ap);
bool set_byte(char **str, va_list ap);
bool set_string(char **str, va_list ap);
bool set_char(char **str, va_list ap);
bool set_bool(char **str, va_list ap);
bool set_ptr(char **str, va_list ap);
bool set_float(char **str, va_list ap);

bool set_char2(char **str, char c);

bool set_number_base(char **str, long long number, unsigned int base);

int my_printf(const char *format, ...);
int my_dprintf(int fd, const char *format, ...);
char *my_saprintf(const char *format, ...);

int my_vprintf(const char *format, va_list ap);
int my_vdprintf(int fd, const char *format, va_list ap);
char *my_vsaprintf(const char *format, va_list ap);

#endif /* !PRINTF_H_ */
