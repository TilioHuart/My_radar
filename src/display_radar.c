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

void
check_mvt_col(radar_t *radar, sfClock *clock, float seconds, sfVector2f *mvt)
{
    if (seconds > 0.05) {
        for (int i = 0; radar->plane[i] != NULL; i += 1) {
            mvt_plane(radar, seconds, mvt, i);
            collision(radar, &i);
        }
        sfClock_restart(clock);
    }
}

void check_display_plane(radar_t *radar, int i)
{
    sfRenderWindow_drawSprite(radar->window, radar->plane[i]->sprite,
                      NULL);
    if (radar->plane[i]->hitbox == 1)
        sfRenderWindow_drawRectangleShape(radar->window,
            radar->plane[i]->rectangle, NULL);
}

void display_plane(radar_t *radar)
{
    for (int i = 0; radar->plane[i] != NULL; i += 1) {
        if (radar->plane[i]->disp == 0) {
            check_display_plane(radar, i);
        }
    }
}

void check_display_tower(radar_t *radar, int i)
{
    sfRenderWindow_drawSprite(radar->window, radar->tower[i]->sprite,
                          NULL);
    if (radar->tower[i]->hitbox == 1)
        sfRenderWindow_drawCircleShape(radar->window, radar->tower[i]->circle,
            NULL);
}

int display_radar(radar_t *radar, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = (float)((double)time.microseconds / 1000000.0);
    sfVector2f mvt;

    sfRenderWindow_clear(radar->window, sfWhite);
    sfRenderWindow_drawSprite(radar->window, radar->map->sprite, NULL);
    for (int i = 0; radar->tower[i] != NULL; i += 1) {
        check_display_tower(radar, i);
    }
    check_mvt_col(radar, clock, seconds, &mvt);
    display_plane(radar);
    sfRenderWindow_display(radar->window);
    return 0;
}
