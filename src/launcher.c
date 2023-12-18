/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** launcher.c
*/

#include "radar.h"

int launcher(char **av)
{
    radar_t *radar;
    sfVideoMode VideoMode = {1920, 1080, 32};

    radar = malloc(sizeof(radar_t));
    radar->window = sfRenderWindow_create(VideoMode, "My_Radar", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(radar->window, 120);
    return 0;
}