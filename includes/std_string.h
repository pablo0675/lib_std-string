#ifndef LIB_STD_STRING_LIBRARY_H
#define LIB_STD_STRING_LIBRARY_H

#include <stdlib.h>
#include <string.h>

typedef struct string_s {
    char *data;
    size_t length;
    size_t capacity;

    void (*resize)(struct string_s *s, size_t n);
    void (*reserve)(struct string_s *s, size_t n);
    const char* (*to_str)(struct string_s *s);
    size_t (*get_length)(struct string_s *s);
    char* (*get_data)(struct string_s *s);
    size_t (*get_capacity)(struct string_s *s);
    struct string_s* (*create)(char *s);
    void (*destroy)(struct string_s *s);
    void (*push_back)(struct string_s *s, char c);
    void (*clear)(struct string_s *s);
    int (*empty)(struct string_s *s);
    char **(*to_array)(struct string_s *s, char delimiter);
    char (*at)(struct string_s *s, size_t pos);
    struct string_s (*copy)(struct string_s *s);
    void (*append)(struct string_s *s, struct string_s *s2);
} string;

// Constructors
string string_create(char *s);
void string_init(string *s);
void string_destroy(string *s);

// Modifiers
void string_resize(string *s, size_t n);
void string_reserve(string *s, size_t n);
void string_push_back(string *s, char c);
void string_clear(string *s);
int string_empty(string *s);

// Operations
string copy_string(string *s);
void string_append(string *s, string *s2);

// Converters
const char* string_to_str(string *s);
char **to_array(string *s, char delimiter);

// get infos
size_t get_length(string *s);
char *get_data(string *s);
size_t get_capacity(string *s);
char get_char_at(string* s, size_t pos);

#endif //LIB_STD_STRING_LIBRARY_H
