/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c
** File description:
** Write a function that splits a
** string into words. Separators
** will all be non-alphanumeric characters.
** The function returns an array
** in which each cell contains
** the address of a string
** (representing a word).
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static int ismap(char c)
{
    if (my_isnum(c) == 0 || c == 65 || c == 84 || c == 32) {
        return 0;
    } else {
        return 1;
    }
}

static void find_len(char const *str, int *len, int *y)
{
    if (ismap(str[*y]) == 0)
        *len += 1;
}

static char **len_char(const char *str)
{
    int len = 0;
    int count = 0;
    char **arr = NULL;
    int y = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '\n')
            count += 1;
    }
    arr = malloc(sizeof(char *) * (count + 2));
    for (int i = 0; i != count; i += 1) {
        for (; str[y] != '\n'; y += 1) {
            find_len(str, &len, &y);
        }
        y += 1;
        arr[i] = malloc(sizeof(char) * len + 1);
        len = 0;
    }
    return arr;
}

static void loop(const char *str, char **arr, int *a, int *y)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (ismap(str[i]) == 0 && ismap(str[i + 1]) == 0) {
            arr[*y][*a] = str[i];
            *a += 1;
        }
        if (ismap(str[i]) == 0 && ismap(str[i + 1]) == 1 &&
            str[i + 1] != '\n') {
            arr[*y][*a] = str[i];
            *a += 1;
        }
        if (ismap(str[i]) == 0 && str[i + 1] == '\n') {
            arr[*y][*a] = str[i];
            *a += 1;
            arr[*y][*a] = '\0';
            *y += 1;
            *a = 0;
        }
    }
    arr[*y] = NULL;
}

char **my_str_to_word_array(const char *str)
{
    char **arr = NULL;
    int a = 0;
    int y = 0;

    if (str == NULL)
        return NULL;
    arr = len_char(str);
    loop(str, arr, &a, &y);
    return arr;
}
