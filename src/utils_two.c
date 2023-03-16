/*
 * project: lib_std-string 
 * author: Pablo Levy
 * date: 3/16/23
 * description: utils_two.c
*/

#include "std_string.h"

void string_append(string *s, string *s2)
{
    string_reserve(s, s->length + s2->length);
    memcpy(s->data + s->length, s2->data, s2->length);
    s->length += s2->length;
    s->data[s->length] = '\0';
}