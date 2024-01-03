/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** mvt_plane.c
*/

#include "radar.h"

void mvt_plane(radar_t *radar, float seconds, sfVector2f *mvt, int i)
{
    sfVector2f stop;

    if (radar->plane[i]->disp == 0) {
        (*mvt).x = radar->plane[i]->vecteurnormal.x *
            (float)radar->plane[i]->speed * seconds;
        (*mvt).y = radar->plane[i]->vecteurnormal.y *
            (float)radar->plane[i]->speed * seconds;
        sfSprite_move(radar->plane[i]->sprite, (*mvt));
        sfRectangleShape_move(radar->plane[i]->rectangle, (*mvt));
        stop = sfSprite_getPosition(radar->plane[i]->sprite);
        if (((*mvt).y > 0 && stop.y > (float)radar->plane[i]->pos_f.y) ||
            ((*mvt).y < 0 && stop.y < (float)radar->plane[i]->pos_f.y) ||
            ((*mvt).x > 0 && stop.x > (float)radar->plane[i]->pos_f.x) ||
            ((*mvt).x < 0 && stop.x < (float)radar->plane[i]->pos_f.x))
            radar->plane[i]->disp = 1;
    }
}
