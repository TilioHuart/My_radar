/*
** EPITECH PROJECT, 2023
** ok
** File description:
** ok
*/

#include <stdio.h>
#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0' && i != n + 1; i += 1) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        if (i == n && s1[i] == s2[i])
            return s1[i] - s2[i];
    }
}
