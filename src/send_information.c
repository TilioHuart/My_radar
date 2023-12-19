/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** send_information.c
*/

#include "radar.h"


static int ismap(char c)
{
    if (my_isnum(c) == 0 || c == 65 || c == 84) {
        return 0;
    } else {
        return 1;
    }
}

static char **len_char(const char *str)
{
    int a = 0;
    int len = 0;
    int count = 0;
    char **arr = NULL;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == ' ' || str[i] == '\0')
            count += 1;
    }
    arr = malloc(sizeof(char *) * (count + 10));
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (ismap(str[i]) == 0 && ismap(str[i + 1]) == 0)
            len += 1;
        else if ((ismap(str[i]) == 0 && str[i += 1] == ' ') ||
                (ismap(str[i]) == 0 && str[i += 1] == '\0')) {
            len += 1;
            arr[a] = malloc(sizeof(char *) * len);
            len = 0;
            a += 1;
        }
        arr[a] = malloc(sizeof(char *) + 2);
    }
    return arr;
}

static void loop(const char *str, char **arr, int *a, int *y)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (ismap(str[i]) == 0 && ismap(str[i + 1]) == 0) {
            arr[*y][*a] = str[i];
            *a += 1;
        }
        if (ismap(str[i]) == 0 && str[i + 1] == ' ') {
            arr[*y][*a] = str[i];
            *a += 1;
            arr[*y][*a] = '\0';
            *y += 1;
            *a = 0;
        }
        if (ismap(str[i]) == 0 && str[i + 1] == '\0') {
            arr[*y][*a] = str[i];
            *a += 1;
            arr[*y][*a] = '\0';
            *y += 1;
            *a = 0;
        }
    }
    arr[*y] = NULL;
}

char **my_info_to_array(const char *str)
{
    char **arr = NULL;
    int a = 0;
    int y = 0;

    if (str == NULL)
        return NULL;
    arr = len_char(str);
    loop(str, arr, &a, &y);
    return arr;
}

static int count_plane(radar_t *radar)
{
    int count = 0;
    int i = 0;

    while (radar->info[i] != NULL) {
        if (radar->info[i][0] == 'A')
            count += 1;
        i += 1;
    }
    return count;
}

static int count_radar(radar_t *radar)
{
    int count = 0;
    int i = 0;

    while (radar->info[i] != NULL) {
        if (radar->info[i][0] == 'T')
            count += 1;
        i += 1;
    }
    return count;
}

int send_information(radar_t *radar)
{
    char **info_line = NULL;
    int i = 0;
    int nb_plane = 0;
    int nb_radar = 0;

    nb_plane = count_plane(radar);
    nb_radar = count_radar(radar);
    info_line = my_info_to_array(radar->info[0]);
    my_show_word_array(info_line);
    while (info_line[i] != NULL) {
        free(info_line[i]);
        i += 1;
    }
    free(info_line);
    return 0;
}