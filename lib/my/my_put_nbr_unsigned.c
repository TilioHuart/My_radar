/*
** EPITECH PROJECT, 2023
** myputnbunsigned
** File description:
** return unsigned in
*/

#include "my.h"

int my_put_nbr_unsigned(unsigned int nb)
{
    int d;
    int u;
    int nbnb = 0;

    d = nb / 10;
    u = nb % 10;
    if (d != 0)
        nbnb += my_put_nbr_unsigned(d);
    my_putchar(u + '0');
    nbnb += 1;
    return nbnb;
}
