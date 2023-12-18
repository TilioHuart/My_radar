/*
** EPITECH PROJECT, 2023
** ok
** File description:
** ok
*/

#include <stdio.h>
#include "my.h"

int my_find_prime_sup(int nb)
{
    int i = nb;

    while (nb != 2147483647) {
        if (my_is_prime(nb) == 1)
            return nb;
        else
            nb += 1;
    }
}
