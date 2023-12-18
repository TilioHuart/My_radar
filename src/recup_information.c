/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** recup_information.c
*/

#include "radar.h"

int recup_information(char **av)
{
    char **array = NULL;
    char *map = read_info(av);

    array = my_str_to_word_array(map);
    my_show_word_array(array);
    return 0;
}