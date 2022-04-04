/*
** EPITECH PROJECT, 2022
** lib
** File description:
** error
*/

#ifndef ERROR_H_
    #define ERROR_H_

    #include "alloc.h"
    #include "asm.h"
    #include "debug.h"

    #define ASSERT(condition, message)\
    ((condition) == false) ?\
    raise(84, message) : 0

    #define RAISE(error_code, message)\
    raise(error_code, message)

int raise(int code, const char *message);

#endif /* !ERROR_H_ */
