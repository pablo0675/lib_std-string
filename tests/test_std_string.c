/*
 * project: lib_std-string 
 * author: Pablo Levy
 * date: 3/16/23
 * description: test_std_string.c
*/

#include <stdio.h>
#include "../includes/std_string.h"

#include "criterion/criterion.h"

Test(std_string, string_create)
{
    string s = string_create("Hello World!");
    cr_assert_str_eq(s.data, "Hello World!");
    cr_assert_eq(s.length, 12);
    cr_assert_eq(s.capacity, 12);
    s.destroy(&s);
}

Test(std_string, string_push_back)
{
    string s = string_create("Hello World!");
    s.push_back(&s, '!');
    cr_assert_str_eq(s.data, "Hello World!!");
    cr_assert_eq(s.length, 13);
    s.destroy(&s);
}

Test(std_string, string_resize)
{
    string s = string_create("Hello World!");
    s.resize(&s, 5);
    cr_assert_str_eq(s.data, "Hello");
    cr_assert_eq(s.length, 5);
    cr_assert_eq(s.capacity, 12);
    s.destroy(&s);
}

Test(std_string, string_reserve)
{
    string s = string_create("Hello World!");
    s.reserve(&s, 20);
    cr_assert_str_eq(s.data, "Hello World!");
    cr_assert_eq(s.length, 12);
    cr_assert_eq(s.capacity, 20);
    s.destroy(&s);
}

Test(std_string, string_clear)
{
    string s = string_create("Hello World!");
    s.clear(&s);
    cr_assert_str_eq(s.data, "");
    cr_assert_eq(s.length, 0);
    cr_assert_eq(s.capacity, 12);
    s.destroy(&s);
}

Test(std_string, string_empty)
{
    string s = string_create("Hello World!");
    cr_assert_eq(s.empty(&s), 0);
    s.clear(&s);
    cr_assert_eq(s.empty(&s), 1);
    s.destroy(&s);
}

Test(std_string, string_to_str)
{
    string s = string_create("Hello World!");
    cr_assert_str_eq(s.to_str(&s), "Hello World!");
    s.destroy(&s);
}

Test(std_string, string_to_array)
{
    string s = string_create("Hello World!");
    char **array = s.to_array(&s, ' ');
    cr_assert_str_eq(array[0], "Hello");
    cr_assert_str_eq(array[1], "World!");
    s.destroy(&s);
}

Test(std_string, string_destroy)
{
    string s = string_create("Hello World!");
    s.destroy(&s);
    cr_assert_eq(s.data, NULL);
    cr_assert_eq(s.length, 0);
    cr_assert_eq(s.capacity, 0);
}

Test(std_string, string_copy)
{
    string s = string_create("Hello World!");
    string s2 = s.copy(&s);
    cr_assert_str_eq(s2.data, "Hello World!");
    cr_assert_eq(s2.length, 12);
    cr_assert_eq(s2.capacity, 12);
    s.destroy(&s);
    s2.destroy(&s2);
}

Test(std_string, string_append)
{
    string s = string_create("Hello World!");
    string s2 = string_create("Hello World!");
    s.append(&s, &s2);
    cr_assert_str_eq(s.data, "Hello World!Hello World!");
    cr_assert_eq(s.length, 24);
    cr_assert_eq(s.capacity, 24);
    s.destroy(&s);
    s2.destroy(&s2);
}

Test(get_infos, get_length)
{
    string s = string_create("Hello World!");
    cr_assert_eq(get_length(&s), 12);
    s.destroy(&s);
}

Test(get_infos, get_capacity)
{
    string s = string_create("Hello World!");
    cr_assert_eq(get_capacity(&s), 12);
    s.destroy(&s);
}

Test(get_infos, get_data)
{
    string s = string_create("Hello World!");
    cr_assert_str_eq(get_data(&s), "Hello World!");
    s.destroy(&s);
}

Test(std_string, string_at)
{
    string s = string_create("Hello World!");
    cr_assert_eq(s.at(&s, 0), 'H');
    cr_assert_eq(s.at(&s, 1), 'e');
    cr_assert_eq(s.at(&s, 2), 'l');
    cr_assert_eq(s.at(&s, 3), 'l');
    cr_assert_eq(s.at(&s, 4), 'o');
    cr_assert_eq(s.at(&s, 5), ' ');
    cr_assert_eq(s.at(&s, 6), 'W');
    cr_assert_eq(s.at(&s, 7), 'o');
    cr_assert_eq(s.at(&s, 8), 'r');
    cr_assert_eq(s.at(&s, 9), 'l');
    cr_assert_eq(s.at(&s, 10), 'd');
    cr_assert_eq(s.at(&s, 11), '!');
    s.destroy(&s);
}