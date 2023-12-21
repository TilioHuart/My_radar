/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** initialisation.c
*/

#include "radar.h"

int initialisation(radar_t *radar, char **info)
{
    sfVideoMode VideoMode = {1920, 1080, 32};

    radar->window = sfRenderWindow_create(VideoMode, "My_Radar",
        sfDefaultStyle, NULL);
    radar->info = info;
    return 0;
}
