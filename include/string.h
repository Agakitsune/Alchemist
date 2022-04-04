/*
** EPITECH PROJECT, 2022
** lib
** File description:
** string
*/

#ifndef STRING_H_
    #define STRING_H_

    #include <stdint.h>

    #include "alloc.h"

/**
    * @brief Concatenate <source> to <destination>
    *
    * @param destination
    * @param source
    * @return char*
*/
char *my_strcat(char *destination, const char *source);

/**
    * @brief Concatenate <n> bytes from <source> to <destination>
    *
    * @param destination
    * @param source
    * @param n The number of byte you want from source
    * @return char* The concatenated char *
*/
char *my_strncat(char *destination, const char *source, size_t n);

/**
    * @brief Search the first occurence of <chr> in <str>
    *
    * @param str The <str> to search in
    * @param chr The <chr> to search
    * @return char* The pointer that point to the first occurence of
    * <chr> in <str>
*/
char *my_strchr(const char *str, char chr);

/**
    * @brief Search the last occurence of <chr> in <str>
    *
    * @param str The <str> to search in
    * @param chr The <chr> to search
    * @return char* The pointer that point to the first occurence of
    * <chr> in <str>
*/
char *my_strrchr(const char *str, char chr);

/**
    * @brief Compare the content of <str1> with <str2>
    *
    * @param str1
    * @param str2
    * @return int Negative if <str1> is "lower than" <str2>
    * Positive if <str1> is "greater than" <str2>
    * 0 if <str1> is equal to <str2>
*/
int my_strcmp(const char *str1, const char *str2);

/**
    * @brief Compare the content of <str1> with <str2>
    *
    * @param str1
    * @param str2
    * @param n The number of bytes you want to be compared
    * @return int Negative if <str1> is "lower than" <str2>,
    * Positive if <str1> is "greater than" <str2>, 0 if <str1> is equal to <str2>
*/
int my_strncmp(const char *str1, const char *str2, size_t n);

/**
    * @brief Copy from <source> to <destination>
    *
    * @param destination
    * @param source
    * @return char*
*/
char *my_strcpy(char *destination, const char *source);

/**
    * @brief Copy <n> bytes from <source> to <destination>
    *
    * @param destination
    * @param source
    * @param n The number of bytes to want to be copied
    * @return char*
*/
char *my_strncpy(char *destination, const char *source, size_t n);

/**
    * @brief Calculate the length (in bytes) of the chunk in <str>
    * that contains bytes in <accept>
    *
    * @param str
    * @param accept
    * @return size_t The length of the chunk
*/
size_t my_strspn(const char *str, const char *accept);

/**
    * @brief Calculate the length (in bytes) of the chunk in <str>
    * that do not contains bytes in <reject>
    *
    * @param str
    * @param reject
    * @return size_t The length of the chunk
*/
size_t my_strcspn(const char *str, const char *reject);

/**
    * @brief Allocate (with malloc) space to hold the bytes of <str>
    *
    * @param str
    * @return char* A pointer to the allocated space
*/
char *my_strdup(const char *str);

/**
    * @brief Allocate (with malloc) space to hold <n> bytes from <str>
    *
    * @param str
    * @param n The number of bytes to want from <str> to be allocated
    * @return char* A pointer to the allocated space
*/
char *my_strndup(const char *str, size_t n);

/**
    * @brief Return a short description of the error code passed in <errnum>
    *
    * @param errnum The error code
    * @return char* The description of the error
*/
char *my_strerror(int errnum);

/**
    * @brief Calculate the length of <str>
    *
    * @param str
    * @return size_t The length of <str>
*/
size_t my_strlen(const char *str);

/**
    * @brief Search the first occurence of a bytes in <accept> in <str>
    *
    * @param str The char * to search in
    * @param accept The char * to search from
    * @return char* The char * that point to the first occurence of a byte in <aceept> in <str>
*/
char *my_strpbrk(const char *str, const char *accept);

/**
    * @brief Return the first token in <str>
    * that is before a byte contained in <delim>,
    * <str> is update to point after that byte
    *
    * @param str The pointer to the char * to search in
    * @param delim The char * containing the delimiters
    * @return char* The token
*/
char *my_strsep(char **str, const char *delim);

/**
    * @brief Return a pointer to the first occurence of <search_str> in <str>
    *
    * @param str
    * @param search_str
    * @return char*
*/
char *my_strstr(const char *str, const char *search_str);

/**
    * @brief Breaks <str> into tokens separated by bytes in <delim>.
    * On the first call, <str> should be not NULL,
    * to reuse the same data <str> should be set to NULL
    *
    * @param str The char * to be parsed (Set to NULL to reuse the old <str>)
    * @param delim The char * containing the delimiters
    * @return char* The token
*/
char *my_strtok(char *str, const char *delim);

/**
    * @brief Breaks <str> into tokens separated by bytes in <delim>.
    * If <str> is NULL, the char * pointed by old will be used,
    * old will be set after the delimiter if a token is found, NULL if not
    *
    * @param str The char * to be parsed
    * @param delim The char * containing the delimiters
    * @param old The pointer to the old parsing char *
    * @return char* The token
*/
char *my_strtok_r(char *str, const char *delim, char **old);

/**
    *@brief Convert the actual string pointed by <nptr> into a number
    * (if the string contains numeric char) and return it.
    * <endptr> is set to point after the number in the string
    *
    *@param nptr
    *@param endptr
    *@return int64_t
*/
int64_t my_strtoll(const char *nptr, char **endptr);

#endif /* !STR_H_ */
