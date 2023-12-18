/*
** EPITECH PROJECT, 2023
** my put nbr oct
** File description:
** convert decimal in octa
*/

#include "my.h"

int my_put_nbr_oct(unsigned int nb)
{
    int d;
    int u;
    int nbnb = 0;

    d = nb / 8;
    u = nb % 8;
    if (d != 0)
        nbnb += my_put_nbr_oct(d);
    my_putchar(u + '0');
    nbnb += 1;
    return nbnb;
}
