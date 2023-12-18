/*
** EPITECH PROJECT, 2023
** flags 1
** File description:
** group flags
*/

#include "my.h"
#include <stdarg.h>

int case_of_number(va_list list)
{
    int len = 0;

    len += my_putnbr(va_arg(list, int));
    return len;
}

int case_of_char(va_list list)
{
    int len = 0;

    len += my_putchar(va_arg(list, int));
    return len;
}

int case_of_percent(va_list __attribute__((unused)) list)
{
    int len = 0;

    len += my_putchar('%');
    return len;
}

int case_of_str(va_list list)
{
    int len = 0;

    len += my_putstr(va_arg(list, char *));
    return len;
}

int case_of_err(void)
{
    char str[] = "error";

    my_putstr(str);
    return -1;
}
