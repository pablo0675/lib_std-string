/*
 * project: lib_std-string 
 * author: Pablo Levy
 * date: 3/16/23
 * description: to_array.c
*/

#include "std_string.h"

char **to_array(string* s, char delimiter)
{
    if (s == NULL) {
        return NULL;
    }
    char **array = malloc(sizeof(char *) * (s->length + 1));
    if (array == NULL) {
        return NULL;
    }
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    while (i < s->length) {
        if (s->data[i] == delimiter) {
            array[j] = malloc(sizeof(char) * (i - k + 1));
            if (array[j] == NULL) {
                return NULL;
            }
            memcpy(array[j], s->data + k, i - k);
            array[j][i - k] = '\0';
            j++;
            k = i + 1;
        }
        i++;
    }
    array[j] = malloc(sizeof(char) * (i - k + 1));
    if (array[j] == NULL) {
        return NULL;
    }
    memcpy(array[j], s->data + k, i - k);
    array[j][i - k] = '\0';
    array[j + 1] = NULL;
    return array;
}