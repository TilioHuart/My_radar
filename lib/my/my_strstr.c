/*
** EPITECH PROJECT, 2023
** ok
** File description:
** ok
*/

#include "my.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    char *recup_str;
    int a = 0;
    int stop = 0;

    while (str[i] != '\0' && str[i] != to_find[0]) {
        i = i + 1;
    }
    if (str[i] == '\0')
        return NULL;
    recup_str = &str[i];
    return recup_str;
}
