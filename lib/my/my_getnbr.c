/*
** EPITECH PROJECT, 2023
** ok
** File description:
** ok
*/

#include <stdio.h>
#include "my.h"

int my_getnbr(char const *str)
{
    int nb = 0;
    int count = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (my_isnum(str[i]) == 0) {
            nb *= 10;
            nb += (str[i] - 48);
        }
        if (str[i] == '-')
            count += 1;
        if ((count % 2) == 0 && my_isnum(str[i]) == 0 &&
            my_isnum(str[i + 1]) == 1)
            return nb;
        if (my_isnum(str[i]) == 0 && my_isnum(str[i + 1]) == 1 &&
            (count % 2) == 1)
            return nb * (-1);
        if (my_isnum(str[i]) == 0 && my_isnum(str[i + 1]) == 1 && count == 0) {
            return nb;
        }
    }
}
