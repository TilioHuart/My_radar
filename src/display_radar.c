/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** display_radar.c
*/

#include "radar.h"

void mvt_plane(radar_t *radar, float seconds, sfVector2f *mvt, int i)
{
    sfVector2f stop;

    if (radar->plane[i]->disp == 0) {
        sfRenderWindow_drawSprite(radar->window, radar->plane[i]->sprite,
            NULL);
        sfRenderWindow_drawRectangleShape(radar->window,
            radar->plane[i]->rectangle, NULL);
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

static int collision(radar_t *radar)
{
    sfVector2f pos;
    sfVector2f pos2;

    for (int i = 0; radar->plane[i] != NULL; i += 1) {
        pos = sfSprite_getPosition(radar->plane[i]->sprite);
        for (int y = 0; radar->plane[y] != NULL; y += 1) {
            if (y != i) {
                pos2 = sfSprite_getPosition(radar->plane[y]->sprite);
                if (radar->plane[i]->disp == 0 && radar->plane[y]->disp == 0)
                    if (abs(pos.x - pos2.x) < (20 / 2 + 20 / 2) && abs(pos.y - pos2.y) < (20 / 2 + 20 / 2)) {
                        radar->plane[i]->disp = 1;
                        radar->plane[y]->disp = 1;
                    }
            }
        }
    }
    return 0;
}

int display_radar(radar_t *radar, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = (float)(time.microseconds / 100000.0);
    sfVector2f mvt;

    sfRenderWindow_clear(radar->window, sfWhite);
    sfRenderWindow_drawSprite(radar->window, radar->map->sprite, NULL);
    for (int i = 0; radar->tower[i] != NULL; i += 1) {
        sfRenderWindow_drawSprite(radar->window, radar->tower[i]->sprite,
            NULL);
        sfRenderWindow_drawCircleShape(radar->window, radar->tower[i]->circle,
            NULL);
    }
    if (seconds > 0.02) {
        for (int i = 0; radar->plane[i] != NULL; i += 1) {
            mvt_plane(radar, seconds, &mvt, i);
            collision(radar);
        }
        sfClock_restart(clock);
        sfRenderWindow_display(radar->window);
    }
    return 0;
}
