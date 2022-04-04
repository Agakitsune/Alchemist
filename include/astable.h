/*
** EPITECH PROJECT, 2022
** lib
** File description:
** Astable - a json parser
*/

#ifndef ASTABLE_H_
    #define ASTABLE_H_

    #include <stdbool.h>
    #include <stddef.h>
    #include <stdlib.h>

    #include "buffer.h"
    #include "string.h"

typedef enum json_type json_type_t;

typedef union json_data json_data_t;

typedef struct json json_t;
typedef struct json_entry json_entry_t;
typedef struct json_object json_object_t;
typedef struct json_array json_array_t;

enum json_type {
    NONE,
    BOOLEAN,
    NUMBER,
    STRING,
    ARRAY,
    OBJECT
};

union json_data {
    void *null;
    bool boolean;
    double number;
    char *string;
    json_array_t *array;
    json_object_t *object;
};

struct json {
    json_type_t _type;
    json_data_t _data;
};

struct json_entry {
    char *name;
    json_t _data;
};

struct json_object {
    size_t _size;
    json_entry_t *_data;
};

struct json_array {
    size_t _size;
    json_t *_data;
};

struct cmd {
    char *flag;
    bool (*func)(json_t *json, buffer_t *buffer);
};

/**
    * @brief Set <json> with data from the file passed in <filepath>
    *
    * @param json The pointer to the JSON object
    * @param filepath The path to the file
    * @return bool: True if the data have been correctly parsed,
    * False otherwise
    */
bool from_file(json_t *json, const char *filepath);

bool is_object(json_t *json);
bool is_array(json_t *json);
bool is_string(json_t *json);
bool is_number(json_t *json);
bool is_boolean(json_t *json);
bool is_null(json_t *json);

json_t *get_from_name(json_object_t *object, const char *name);
json_t *get_from_index(json_array_t *array, size_t index);
json_object_t *get_as_object(json_t *json);
json_array_t *get_as_array(json_t *json);
char *get_as_string(json_t *json);
double get_as_number(json_t *json);
bool get_as_boolean(json_t *json);
void *get_as_null(json_t *json);

/*
*
*   Do not use those functions, they are here for parsing purposes only
*
*/

void skip_whitespace(buffer_t *buffer);

bool get_value(json_t *value, buffer_t *buffer);
json_data_t *get_data(json_t *json, buffer_t *buffer);
bool get_object(json_t *json, buffer_t *buffer);
bool get_string(json_t *json, buffer_t *buffer);
bool get_array(json_t *json, buffer_t *buffer);
bool get_number(json_t *json, buffer_t *buffer);
bool get_bool(json_t *json, buffer_t *buffer);
bool get_null(json_t *json, buffer_t *buffer);
json_entry_t *get_entry(buffer_t *buffer);

void json_move_to(buffer_t *buffer, size_t size);
#endif /* !JSON_H_ */
