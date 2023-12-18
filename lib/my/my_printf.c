/*
** EPITECH PROJECT, 2023
** my_printf.c
** File description:
** printf
*/

#include "struct_flag.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int loop_struct(int *i, va_list list, const char *format, elem_t *arr)
{
    int len = 0;

    for (int y = 0; y != 20; y += 1) {
        if (format[*i + 1] == arr[y].flag) {
            len = arr[y].pfunction(list);
            *i += 1;
            return len;
        }
    }
    return -2147483648;
}

int my_printf(const char *format, ...)
{
    elem_t *arr;
    va_list list;
    int len = 0;

    va_start(list, format);
    arr = malloc(sizeof(elem_t) * 21);
    struct_debut(arr, list);
    struct_suite(arr, list);
    for (int i = 0; format[i] != '\0'; i += 1) {
        if (format[i] == '%')
            len += loop_struct(&i, list, format, arr);
        else
            len += my_putchar(format[i]);
    }
    if (len < 0)
        return 84;
    va_end(list);
    free(arr);
    return len;
}
