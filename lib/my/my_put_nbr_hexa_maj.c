/*
** EPITECH PROJECT, 2023
** my_put_nbr_hexa_maj.c
** File description:
** hexa
*/

#include <stdio.h>
#include "my.h"

int my_put_nbr_hexa_maj(unsigned int nb)
{
    int d;
    int u;
    int nbnb = 0;

    d = nb / 16;
    u = nb % 16;
    if (d != 0)
        nbnb += my_put_nbr_hexa_maj(d);
    if (u > 9)
        my_putchar(u + 55);
    else
        my_putchar(u + '0');
    nbnb += 1;
    return nbnb;
}
