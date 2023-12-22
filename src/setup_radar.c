/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** setup_radar.c
*/

#include "radar.h"

int setup_radar(radar_t *radar, char **info_line, int nb_radar)
{
    static int i = 0;
    radar->texture_tower = sfTexture_createFromFile("assets/tower.png", NULL);

    if (i < nb_radar) {
        radar->tower[i] = malloc(sizeof(plane_t));
        if (radar->tower[i] == NULL)
            return 84;
        radar->tower[i]->pos.x = my_getnbr(info_line[1]);
        radar->tower[i]->pos.y = my_getnbr(info_line[2]);
        radar->tower[i]->radius = my_getnbr(info_line[3]);
        radar->tower[i]->sprite = sfSprite_create();
        sfSprite_setTexture(radar->tower[i]->sprite, radar->texture_tower, sfTrue);
        sfSprite_setOrigin(radar->tower[i]->sprite, (sfVector2f) {250, 250});
        sfSprite_setScale(radar->tower[i]->sprite, (sfVector2f){(float)0.1, (float)0.1});
        sfSprite_setPosition(radar->tower[i]->sprite, (sfVector2f){(float)radar->tower[i]->pos.x, (float)radar->tower[i]->pos.y});
        i += 1;
    }
    radar->tower[nb_radar] = NULL;
    return 0;
}
