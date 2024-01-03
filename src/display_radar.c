/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** display_radar.c
*/

#include "radar.h"

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
    if (radar->plane[i]->disp_s == 1)
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
    if (radar->tower[i]->disp_s == 1)
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
