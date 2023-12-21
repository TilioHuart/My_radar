/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** recup_information.c
*/

#include "radar.h"

static int ismap(char c)
{
    if (my_isnum(c) == 0 || c == 65 || c == 84 || c == 32) {
        return 0;
    } else {
        return 1;
    }
}

char **recup_information(char **av)
{
    char **array = NULL;
    char *map = read_info(av);

    for (int i = 80; map[i - 1] != '\0'; i += 1)
        if (map[i] == '\0' && map[i - 1] != '\n') {
            map[i] = '\n';
            map[i + 1] = '\0';
        }
    for (int i = 0; map[i] != '\0'; i += 1)
        if (ismap(map[i]) == 1 && map[i] != '\n')
            return NULL;
    array = my_str_to_word_array(map);
    free(map);
    return array;
}
