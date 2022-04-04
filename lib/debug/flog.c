/*
** EPITECH PROJECT, 2022
** Raycast
** File description:
** log
*/

#include "debug.h"

void flog(log_type_t type, const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    my_dprintf(2, "[");
    switch (type) {
        case INFO:
            my_dprintf(2, FG_CYAN"INFO"RESET);
            break;
        case WARNING:
            my_dprintf(2, FG_YELLOW"WARNING"RESET);
            break;
        case ERROR:
            my_dprintf(2, FG_RED"ERROR"RESET);
            break;
        case DEBUG:
            my_dprintf(2, FG_MAGENTA"DEBUG"RESET);
            break;
    }
    my_dprintf(2, "] ");
    my_vdprintf(2, format, ap);
    my_dprintf(2, "\n");
    va_end(ap);
};