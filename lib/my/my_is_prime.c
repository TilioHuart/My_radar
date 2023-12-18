/*
** EPITECH PROJECT, 2023
** ok
** File description:
** ok
*/

#include <stdio.h>

int my_is_prime(int nb)
{
    int i = 2;

    while (i != nb) {
        if (nb % i == 0)
            return 0;
        i += 1;
    }
    if (nb == 2)
        return 1;
    if (nb == 1)
        return 0;
    return 1;
}
