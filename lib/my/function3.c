/*
** EPITECH PROJECT, 2023
** function3.c
** File description:
** function
*/

#include <stdarg.h>
#include "my.h"

int case_of_pointer(va_list list)
{
    int len = 0;

    my_putchar(48);
    my_putchar(120);
    len += 2;
    len += my_put_nbr_hexa_min(va_arg(list, int));
    return len;
}

int case_of_float(va_list list)
{
    int len = 0;

    len += my_put_nbr_float(va_arg(list, double));
    return len;
}

int case_of_scientific(va_list list)
{
    int len = 0;

    len += my_put_nbr_scientific(va_arg(list, double));
    return len;
}

int case_of_scientific_maj(va_list list)
{
    int len = 0;

    len += my_put_nbr_scientific_maj(va_arg(list, double));
    return len;
}
