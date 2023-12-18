/*
** EPITECH PROJECT, 2023
** ok
** File description:
** ok
*/

#include "my.h"

int my_str_islower(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] >= 97 && str[i] <= 122)
            count += 1;
    }
    if (count == my_strlen(str))
        return 1;
    else
        return 0;
}
