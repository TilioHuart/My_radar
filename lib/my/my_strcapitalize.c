/*
** EPITECH PROJECT, 2023
** ok
** File description:
** ok
*/

#include "my.h"

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] >= 'a' && str[i] <= 'z' && my_isalpha(str[i - 1]) == 1) {
            str[i] -= 32;
            i += 1;
        }
        if (str[i] >= 'A' && str[i] <= 'Z' && my_isalpha(str[i - 1]) == 1)
            str[i] += 32;
        if (str[i] >= 'A' && str[i] <= 'Z' && my_isalpha(str[i - 1]) == 0)
            str[i] += 32;
    }
    return str;
}
