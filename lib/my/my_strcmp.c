/*
** EPITECH PROJECT, 2023
** ok
** File description:
** ok
*/

#include <string.h>
#include <stdio.h>

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i += 1) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
}
