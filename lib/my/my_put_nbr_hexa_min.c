/*
** EPITECH PROJECT, 2023
** my put nbr hexa min
** File description:
** hexa min
*/

#include "my.h"
#include "struct_flag.h"

int my_put_nbr_hexa_min(unsigned int nb)
{
    int d;
    int u;
    int nbnb = 0;

    d = nb / 16;
    u = nb % 16;
    if (d != 0)
        nbnb += my_put_nbr_hexa_min(d);
    if (u > 9)
        my_putchar(u + 87);
    else
        my_putchar(u + '0');
    nbnb += 1;
    return nbnb;
}
