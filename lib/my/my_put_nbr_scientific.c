/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"

void loop_positive(int *n, double *nb, int *power)
{
    if (*n > 0)
        while (*n > 10) {
            *n /= 10;
            *nb /= 10;
            *power += 1;
        }
}

void loop_negative(int *n, double *nb, int *power)
{
    if (*n < 0)
        while (*n < -10) {
            *n /= 10;
            *nb /= 10;
            *power += 1;
        }
}

void loop2(int *div, int *count)
{
    while ((*div / 10) != 0) {
        *count += 1;
        *div /= 10;
    }
}

void display1(int *temp, int *power, int *len)
{
    if (*temp < 0)
        *temp *= -1;
    *len += my_putchar('.');
    *len += my_putnbr(*temp);
    *len += my_putchar('e');
    *len += my_putnbr(*power);
}

int my_put_nbr_scientific(double nb)
{
    int n = nb;
    int temp = 0;
    int div = 0;
    int count = 1;
    int len = 0;
    int power = 0;

    loop_positive(&n, &nb, &power);
    loop_negative(&n, &nb, &power);
    len += my_putnbr(n);
    n = nb;
    nb *= 1000000;
    temp = nb;
    temp %= 1000000;
    div = temp;
    loop2(&div, &count);
    for (int i = 6 - count; i > 0; i -= 1)
        len += my_putchar('0');
    display1(&temp, &power, &len);
    return len;
}
