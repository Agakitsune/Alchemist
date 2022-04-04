/*
** EPITECH PROJECT, 2022
** Raycast
** File description:
** debug
*/

#ifndef DEBUG_H_
    #define DEBUG_H_

    #include <stdarg.h>

    #include "printf.h"

    #define FLAG        _flag(my_saprintf("Passed flag at line {i} in file {s} at {s}", __LINE__, __FILE__, __TIME__))
    #define BREAKPOINT  _breakpoint(my_saprintf("Breakpoint at line {i} in file {s} at {s}", __LINE__, __FILE__, __TIME__))

    #define RESET               "\033[0m"
    #define FG_BLACK            "\033[0;30m"
    #define FG_RED              "\033[0;31m"
    #define FG_GREEN            "\033[0;32m"
    #define FG_YELLOW           "\033[0;33m"
    #define FG_BLUE             "\033[0;34m"
    #define FG_MAGENTA          "\033[0;35m"
    #define FG_CYAN             "\033[0;36m"
    #define FG_WHITE            "\033[0;37m"
    #define FG_BRIGHT_BLACK     "\033[0;90m"
    #define FG_BRIGHT_RED       "\033[0;91m"
    #define FG_BRIGHT_GREEN     "\033[0;92m"
    #define FG_BRIGHT_YELLOW    "\033[0;93m"
    #define FG_BRIGHT_BLUE      "\033[0;94m"
    #define FG_BRIGHT_MAGENTA   "\033[0;95m"
    #define FG_BRIGHT_CYAN      "\033[0;96m"
    #define FG_BRIGHT_WHITE     "\033[0;97m"

    #define BG_BLACK            "\033[0;40m"
    #define BG_RED              "\033[0;41m"
    #define BG_GREEN            "\033[0;42m"
    #define BG_YELLOW           "\033[0;43m"
    #define BG_BLUE             "\033[0;44m"
    #define BG_MAGENTA          "\033[0;45m"
    #define BG_CYAN             "\033[0;46m"
    #define BG_WHITE            "\033[0;47m"
    #define BG_BRIGHT_BLACK     "\033[0;100m"
    #define BG_BRIGHT_RED       "\033[0;101m"
    #define BG_BRIGHT_GREEN     "\033[0;102m"
    #define BG_BRIGHT_YELLOW    "\033[0;103m"
    #define BG_BRIGHT_BLUE      "\033[0;104m"
    #define BG_BRIGHT_MAGENTA   "\033[0;105m"
    #define BG_BRIGHT_CYAN      "\033[0;106m"
    #define BG_BRIGHT_WHITE     "\033[0;107m"

typedef enum log_type log_type_t;

enum log_type
{
    INFO,
    WARNING,
    ERROR,
    DEBUG
};

void flog(log_type_t type, const char *format, ...);
void _flag(const char *str);
void _breakpoint(const char *str);

#endif /* !DEBUG_H_ */
