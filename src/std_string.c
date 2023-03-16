#include "../includes/std_string.h"

#include <stdio.h>

void string_init(string *s)
{
    s->data = NULL;
    s->length = 0;
    s->capacity = 0;
    s->reserve = &string_reserve;
    s->resize = &string_resize;
    s->push_back = &string_push_back;
    s->clear = &string_clear;
    s->empty = &string_empty;
    s->to_str = &string_to_str;
    s->destroy = &string_destroy;
    s->to_array = &to_array;
    s->at = &get_char_at;
    s->copy = &copy_string;
    s->append = &string_append;


}

string string_create(char *s)
{
    string str;
    string_init(&str);
    str.data = malloc(sizeof(char) * (strlen(s) + 1));
    if (str.data == NULL) {
        return str = (string){NULL, 0, 0, NULL, NULL, NULL, NULL, NULL,
                              NULL, NULL, NULL, NULL,NULL, NULL, NULL, NULL,
                              NULL, NULL};
    }
    strcpy(str.data, s);
    str.length = strlen(s);
    str.capacity = strlen(s);
    return str;
}

void string_destroy(string *s)
{
    free(s->data);
    s->data = NULL;
    s->length = 0;
    s->capacity = 0;
}

void string_push_back(string *s, char c)
{
    if (s->length + 1 > s->capacity) {
        string_reserve(s, s->capacity + 1);
    }
    s->data[s->length] = c;
    s->length++;
    s->data[s->length] = '\0';
}

string copy_string(string *s)
{
    string str;
    string_init(&str);
    str.data = malloc(sizeof(char) * (s->length + 1));
    if (str.data == NULL) {
        return str = (string){NULL, 0, 0, NULL, NULL, NULL, NULL, NULL,
                              NULL, NULL, NULL, NULL,NULL, NULL, NULL, NULL, NULL,
                              NULL};
    }
    strcpy(str.data, s->data);
    str.length = s->length;
    str.capacity = s->capacity;
    return str;
}