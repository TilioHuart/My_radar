/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** recup_information.c
*/

#include "radar.h"

char **recup_information(char **av)
{
    char **array = NULL;
    char *map = read_info(av);

    for (int i = 80; map[i - 1] != '\0'; i += 1) {
        if (map[i] == '\0' && map[i - 1] != '\n') {
            map[i] = '\n';
            map[i + 1] = '\0';
        }
    }
    array = my_str_to_word_array(map);
    free(map);
    return array;
}
