/*
** EPITECH PROJECT, 2023
** ok
** File description:
** ok
*/

#include <stdio.h>
#include "my.h"

char my_getoperator(char const *str)
{
    char nb = 0;
    int i = 0;

    for (i; str[i] != '\0'; i += 1) {
        if (my_isoperator(str[i]) == 0) {
            nb = str[i];
            return nb;
        }
    }
}
