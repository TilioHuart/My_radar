/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** initialisation.c
*/

#include "radar.h"

int initialisation(radar_t *radar)
{
    sfVideoMode VideoMode = {1920, 1080, 32};

    radar->map = malloc(sizeof(map_t));
    radar->window = sfRenderWindow_create(VideoMode, "My_Radar",
        sfDefaultStyle, NULL);
    radar->map->texture = sfTexture_createFromFile("assets/map2.jpg", NULL);
    radar->map->sprite =sfSprite_create();
    sfSprite_setTexture(radar->map->sprite, radar->map->texture, sfTrue);
    return 0;
}
