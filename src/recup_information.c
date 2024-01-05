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

static void check_map(const char *map, int *count_p, int *count_t)
{
    for (int i = 0; map[i] != '\0'; i += 1) {
        if (map[i] == 'A')
            (*count_p) += 1;
        if (map[i] == 'T')
            (*count_t) += 1;
    }
}

static void assign_bn(char *map)
{
    for (int i = 1; map[i - 1] != '\0'; i += 1)
        if (map[i] == '\0' && map[i - 1] != '\n') {
            map[i] = '\n';
            map[i + 1] = '\0';
        }
}

char **recup_information(char **av)
{
    char **array = NULL;
    char *map = read_info(av);
    int count_p = 0;
    int count_t = 0;

    if (map == NULL)
        return NULL;
    assign_bn(map);
    for (int i = 0; map[i] != '\0'; i += 1)
        if ((ismap(map[i]) == 1 && map[i] != '\n') || (map[i] == '\n' && map[i + 1] == '\n'))
            return NULL;
    check_map(map, &count_p, &count_t);
    if (count_p < 1 || count_t < 1)
        return NULL;
    array = my_str_to_word_array(map);
    free(map);
    return array;
}
