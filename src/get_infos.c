/*
 * project: lib_std-string 
 * author: Pablo Levy
 * date: 3/16/23
 * description: get_infos.c
*/

#include "std_string.h"

size_t get_length(string* s)
{
    return s->length;
}

char *get_data(string* s)
{
    return s->data;
}

size_t get_capacity(string* s)
{
    return s->capacity;
}

char get_char_at(string* s, size_t pos)
{
    if (pos >= s->length) {
        return '\0';
    }
    return s->data[pos];
}