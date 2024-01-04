/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** display_radar.c
*/

#include "radar.h"

static void check_time(const radar_t *radar, int time_to_spawn, int i)
{
    if (radar->plane[i]->delete == time_to_spawn)
        radar->plane[i]->spawn = 0;
}

void
check_mvt_col(radar_t *radar, sfClock *clock, float seconds, sfVector2f *mvt)
{
    static int a = 0;
    static int time_to_spawn = 0;

    if (seconds > 0.05) {
        a += 1;
        for (int i = 0; radar->plane[i] != NULL; i += 1) {
            mvt_plane(radar, seconds, mvt, i);
            collision(radar, &i);
            check_time(radar, time_to_spawn, i);
        }
        if (a == 20) {
            a = 0;
            time_to_spawn += 1;
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
        if (radar->plane[i]->disp == 0 && radar->plane[i]->spawn == 0) {
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
