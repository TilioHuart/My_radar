/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** setup_radar.c
*/

#include "radar.h"

static void set_radar(const radar_t *radar, int i)
{
    radar->tower[i]->sprite = sfSprite_create();
    radar->tower[i]->circle = sfCircleShape_create();
    radar->tower[i]->hitbox = 1;
    radar->tower[i]->disp_s = 1;
}

int setup_radar(radar_t *radar, char **info_line, int nb_radar)
{
    static int i = 0;

    for (int y = 0; y != 4; y += 1)
        if (info_line[y] == NULL)
            return 84;
    if (i < nb_radar) {
        radar->tower[i] = malloc(sizeof(plane_t));
        if (radar->tower[i] == NULL)
            return 84;
        radar->tower[i]->pos.x = my_getnbr(info_line[1]);
        radar->tower[i]->pos.y = my_getnbr(info_line[2]);
        radar->tower[i]->radius = my_getnbr(info_line[3]);
        radar->tower[i]->radius *= 1920;
        radar->tower[i]->radius /= 100;
        set_radar(radar, i);
        i += 1;
    }
    radar->tower[nb_radar] = NULL;
    return 0;
}
