/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"

int negative_case_float_min(int *temp, int *len)
{
    if (*temp < 0) {
        *temp *= -1;
    }
    *len += my_putnbr(*temp);
}

int my_put_nbr_float(double nb)
{
    int n = nb;
    int temp = 0;
    int div = 0;
    int count = 1;
    int len = 0;

    len += my_putnbr(n);
    nb *= 1000000;
    temp = nb;
    temp %= 1000000;
    div = temp;
    while ((div / 10) != 0) {
        count += 1;
        div /= 10;
    }
    len += my_putchar('.');
    for (int i = 6 - count; i > 0; i -= 1)
        len += my_putchar('0');
    negative_case_float_min(&temp, &len);
    return len;
}
