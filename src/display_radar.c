/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** display_radar.c
*/

#include "radar.h"

int display_radar(radar_t *radar)
{
    sfRenderWindow_display(radar->window);
    sfRenderWindow_drawSprite(radar->window, radar->map->sprite, NULL);
    for (int i = 0; radar->tower[i] != NULL; i += 1) {
        sfRenderWindow_drawSprite(radar->window, radar->tower[i]->sprite,
            NULL);
        sfRenderWindow_drawCircleShape(radar->window, radar->tower[i]->circle,
            NULL);
    }
    return 0;
}
