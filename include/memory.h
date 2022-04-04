/*
** EPITECH PROJECT, 2022
** lib
** File description:
** memory
*/

#ifndef MEMORY_H_
    #define MEMORY_H_

    #include <stddef.h>
    #include <stdlib.h>

/**
 * @brief Move <n> bytes from <src> to <dest>
 * 
 * @param dest 
 * @param src 
 * @param n The number of bytes you want to move
 * @return void* 
 */
void *move_memory(void *dest, const void *src, size_t n);

/**
 * @brief Set <n> bytes from <src> to the value passed in <data>
 * 
 * @param src 
 * @param data 
 * @param n The number of bytes you want to be set
 * @return void* 
 */
void *set_memory(void *src, unsigned char data, size_t n);

/**
 * @brief Copy <n> bytes from <src> and put it in <dest>
 * 
 * @param dest 
 * @param src 
 * @param n The number of bytes you want to copy
 * @return void* 
 */
void *copy_memory(void *dest, const void *src, size_t n);

/**
 * @brief Search the <chr> bytes in a segment of <n> bytes from block
 * 
 * @param block 
 * @param chr The byte you search
 * @param n The number of bytes of the segment you want to search in
 * @return void* The pointer to the first occurence of <chr> in <block>
 */
void *search_memory(const void *block, unsigned char chr, size_t n);

/**
 * @brief Compare <n> bytes from <ptr1> with <ptr2>
 *  
 * 
 * @param ptr1 
 * @param ptr2 
 * @param n The number of bytes you want to compare
 * @return int Negative if <str1> is "lower than" <str2>, Positive if <str1> is "greater than" <str2>, 0 if <str1> is equal to <str2>
 */
int compare_memory(const void *ptr1, const void *ptr2, size_t n);

#endif /* !MEMORY_H_ */
