/*
 * project: lib_std-string 
 * author: Pablo Levy
 * date: 3/16/23
 * description: utils.c
*/

#include "../includes/std_string.h"

const char* string_to_str(string* s)
{
    return s->data;
}

void string_resize(string* s, size_t n)
{
    if (n < s->length) {
        s->length = n;
        s->data[n] = '\0';
    } else if (n > s->length) {
        string_reserve(s, n);
        memset(s->data + s->length, 0, n - s->length + 1);
        s->length = n;
    }
}

void string_reserve(string* s, size_t n)
{
    if (n > s->capacity) {
        s->data = realloc(s->data, n + 1);
        s->capacity = n;
    }
}

void string_clear(string* s)
{
    s->resize(s, 0);
}

int string_empty(string* s)
{
    return s->length == 0;
}
