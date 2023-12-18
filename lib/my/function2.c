/*
** EPITECH PROJECT, 2023
** function2
** File description:
** functions 2
*/

#include <unistd.h>
#include <stdarg.h>
#include "my.h"
#include "struct_flag.h"

int case_of_octal(va_list list)
{
    int len = 0;

    len += my_put_nbr_oct(va_arg(list, unsigned int));
    return len;
}

int case_of_unsigned(va_list list)
{
    int len = 0;

    len += my_put_nbr_unsigned(va_arg(list, unsigned int));
    return len;
}

int case_of_84(void)
{
    return -2147483647;
}

int case_of_hexa_min(va_list list)
{
    int len = 0;

    len += my_put_nbr_hexa_min(va_arg(list, unsigned int));
    return len;
}

int case_of_hexa_maj(va_list list)
{
    int len = 0;

    len += my_put_nbr_hexa_maj(va_arg(list, unsigned int));
    return len;
}
