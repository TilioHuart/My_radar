/*
** EPITECH PROJECT, 2023
** ok
** File description:
** ok
*/

#include <stdio.h>

int my_isalpha(char c)
{
    if (c >= 65 && c <= 90 || c >= 97 && c <= 122) {
        return 0;
    } else {
        return 1;
    }
}
