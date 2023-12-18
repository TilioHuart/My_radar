/*
** EPITECH PROJECT, 2023
** flags
** File description:
** struct for flags
*/

#include <stdarg.h>

#ifndef STRUCT_FLAG_H_
    #define STRUCT_FLAG_H_

typedef struct elem {
    char flag;
    int (*pfunction)(va_list);
} elem_t;

int case_of_number(va_list list);
int struct_debut(elem_t *arr, va_list list);
int case_of_char(va_list list);
int case_of_octal(va_list list);
int case_of_str(va_list list);
int case_of_percent(va_list list);
int struct_suite(elem_t *arr, va_list list);
int case_of_unsigned(va_list list);
int case_of_84(void);
int case_of_hexa_min(va_list list);
int case_of_hexa_maj(va_list list);
int case_of_pointer(va_list list);
int case_of_float(va_list list);
int case_of_scientific(va_list list);
int case_of_scientific_maj(va_list list);

#endif
