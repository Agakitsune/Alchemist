/*
** EPITECH PROJECT, 2022
** lib
** File description:
** buffer
*/

#ifndef BUFFER_H_
    #define BUFFER_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdbool.h>

    #include "memory.h"
    #include "alloc.h"
    #include "string.h"

typedef unsigned char byte_t;
typedef unsigned long long u64_t;

typedef struct buffer
{
    u64_t size;
    byte_t *content;
    u64_t index;
} buffer_t;

typedef enum byte_order
{
    MY_BIG_ENDIAN,
    MY_LITTLE_ENDIAN
} byte_order_t;

/**
    * @brief Read <n> bytes in the buffer.
    *
    * @param buffer
    * @param n The number of byte you want to read
    * @return byte_t* Return the read bytes
    */
byte_t *read_bytes(buffer_t *buffer, u64_t n);

/**
    * @brief Read <n> bytes in the buffer and convert it into a number.
    * The size must be of 8 maximum.
    *
    * @param buffer
    * @param size The size in bytes of the number
    * @param byte_order The byte order
    * @return u64_t Return the number
    */
long long read_number(buffer_t *buffer, u64_t size, byte_order_t byte_order);

/**
    * @brief Read <n> bytes in the <buffer> and convert it into a string (char *).
    *
    * @param buffer
    * @param n The number of bytes your want to read
    * @return char* Return the null-terminated string
    */
char *read_string(buffer_t *buffer, u64_t n);

/**
    * @brief Read 8 bytes in the <buffer> and convert it into a pointer.
    *
    * @param buffer
    * @return void* Return the pointer
    */
void *read_ptr(buffer_t *buffer);

/**
    * @brief Read <n> bytes in the <buffer> at the position <pos>.
    *
    * @param buffer
    * @param pos The position you want to read the data
    * @param n The number of bytes you want to read
    * @return byte_t* Return the read bytes
    */
byte_t *read_at(buffer_t *buffer, u64_t pos, u64_t n);

/**
    * @brief Skip <n> bytes in the <buffer>.
    *
    * @param buffer
    * @param n The number of bytes you want to skip
    */
void skip_bytes(buffer_t *buffer, u64_t n);

/**
    * @brief Push at the end of the buffer <stream_size> bytes from <stream>
    *
    * @param buffer
    * @param stream
    * @param stream_size The number of bytes you want to push back from <stream>
    */
void push_bytes(buffer_t *buffer, byte_t *stream, u64_t stream_size);

/**
    * @brief Insert at <pos> in the buffer <stream_size> bytes from <stream>
    *
    * @param buffer
    * @param stream
    * @param s_size The number of bytes you want to push back from <stream>
    * @param pos The position of the insertion
    */
void insert_bytes(buffer_t *buffer, byte_t *stream, u64_t s_size, u64_t pos);

/**
    * @brief Reallocate the buffer to hold <size> more bytes
    *
    * @param buffer
    * @param size The number of bytes to want to expand
    */
void expand(buffer_t *buffer, u64_t size);

/**
    * @brief Reallocate the buffer to hold <size> less bytes
    *
    * @param buffer
    * @param size The number of bytes to want to retract
    */
void retract(buffer_t *buffer, u64_t size);

/**
    * @brief Reallocate the buffer to hold <size> bytes
    *
    * @param buffer
    * @param size The number of bytes you want the buffer to hold
    */
void resize(buffer_t *buffer, u64_t size);

/**
    * @brief Go to <pos> in the buffer.
    * If <pos> is invalid (not in the buffer), it does nothing.
    *
    * @param buffer
    * @param pos The position you want to go
    */
void go_to(buffer_t *buffer, u64_t pos);

/**
    * @brief Move <n> bytes in the buffer.
    * <n> can be negative if you want to go back in the buffer.
    * If <n> is invalid (the destination is not in the buffer), it does nothing
    *
    * @param buffer
    * @param n The number of bytes you want to move
    */
void move_to(buffer_t *buffer, long long n);

/**
    * @brief Open a file stored at <filepath>.
    * IF the file does exist, return NULL.
    * The buffer must be dtored using <dtor_buffer>
    *
    * @param filepath The file path
    * @return buffer_t* The buffer of the file, NULL if the file doesn't exist
    */
buffer_t *open_file(const char *filepath);

/**
    * @brief Initialize a new null-terminated buffer.
    * This function is not mandatory to use buffers.
    * It's better to use it if you don't know how this buffer works
    *
    * @param size The size of the buffer
    * @return buffer_t* The buffer, NULL if the allocation failed
    */
buffer_t *new_buffer(u64_t size);

/**
    * @brief dtor a buffer, use it if your buffer have been ctord by <new_buffer>
    *
    * @param buffer
    */
void dtor_buffer(buffer_t *buffer);

#endif /* !BUFFER_H_ */
