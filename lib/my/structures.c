/*
** EPITECH PROJECT, 2023
** struct1.c
** File description:
** sturct which contain differents flags
*/

#include "struct_flag.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int struct_debut(elem_t *arr, va_list list)
{
    arr[0].flag = 'd';
    arr[0].pfunction = &case_of_number;
    arr[1].flag = 'i';
    arr[1].pfunction = &case_of_number;
    arr[2].flag = 'c';
    arr[2].pfunction = &case_of_char;
    arr[3].flag = 's';
    arr[3].pfunction = &case_of_str;
    arr[4].flag = '%';
    arr[4].pfunction = &case_of_percent;
    arr[5].flag = 'o';
    arr[5].pfunction = &case_of_octal;
    arr[6].flag = 'u';
    arr[6].pfunction = &case_of_unsigned;
    arr[7].flag = 'x';
    arr[7].pfunction = &case_of_hexa_min;
    arr[8].flag = 'X';
    arr[8].pfunction = &case_of_hexa_maj;
    arr[9].flag = 'e';
    arr[9].pfunction = &case_of_scientific;
}

int struct_suite(elem_t *arr, va_list list)
{
    arr[10].flag = 'E';
    arr[10].pfunction = &case_of_scientific_maj;
    arr[11].flag = 'f';
    arr[11].pfunction = &case_of_float;
    arr[12].flag = 'F';
    arr[12].pfunction = &case_of_float;
    arr[13].flag = 'g';
    arr[13].pfunction = &case_of_number;
    arr[14].flag = 'G';
    arr[14].pfunction = &case_of_number;
    arr[15].flag = 'a';
    arr[15].pfunction = &case_of_number;
    arr[16].flag = 'A';
    arr[16].pfunction = &case_of_number;
    arr[17].flag = 'n';
    arr[17].pfunction = &case_of_number;
    arr[18].flag = 'm';
    arr[18].pfunction = &case_of_number;
    arr[19].flag = 'p';
    arr[19].pfunction = &case_of_pointer;
}
