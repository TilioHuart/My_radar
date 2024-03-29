/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** setup_plane.c
*/

#include "radar.h"

static void setup_app(const radar_t *radar, int i)
{
    radar->plane[i]->sprite = sfSprite_create();
    radar->plane[i]->rectangle = sfRectangleShape_create();
    radar->plane[i]->hitbox = 1;
    radar->plane[i]->disp_s = 1;
    radar->plane[i]->area = 0;
    radar->plane[i]->spawn = 1;
    radar->plane[i]->line = 0;
}

int setup_plane(radar_t *radar, char **info_line, int nb_plane)
{
    static int i = 0;

    for (int y = 0; y != 7; y += 1)
        if (info_line[y] == NULL)
            return 84;
    if (i < nb_plane) {
        radar->plane[i] = malloc(sizeof(plane_t));
        if (radar->plane[i] == NULL)
            return 84;
        radar->plane[i]->pos_i.x = my_getnbr(info_line[1]);
        radar->plane[i]->pos_i.y = my_getnbr(info_line[2]);
        radar->plane[i]->pos_f.x = my_getnbr(info_line[3]);
        radar->plane[i]->pos_f.y = my_getnbr(info_line[4]);
        radar->plane[i]->speed = my_getnbr(info_line[5]);
        radar->plane[i]->delete = my_getnbr(info_line[6]);
        setup_app(radar, i);
        i += 1;
    }
    radar->plane[nb_plane] = NULL;
    return 0;
}
