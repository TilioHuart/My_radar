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

static int assign_area(radar_t *radar)
{
    radar->area = malloc(sizeof(area_t));
    radar->area->top_left.height = 1080 / 2;
    radar->area->top_left.width = 1920 / 2;
    radar->area->top_left.top = 0;
    radar->area->top_left.left = 0;
    radar->area->top_right.height = 1080 / 2;
    radar->area->top_right.width = 1920 / 2;
    radar->area->top_right.top = 1080 / 2;
    radar->area->top_right.left = 0;
    radar->area->bottom_right.height = 1080 / 2;
    radar->area->bottom_right.width = 1920 / 2;
    radar->area->bottom_right.top = 1080 / 2;
    radar->area->bottom_right.left = 1920 / 2;
    radar->area->bottom_left.height = 1080 / 2;
    radar->area->bottom_left.width = 1920 / 2;
    radar->area->bottom_left.top = 0;
    radar->area->bottom_left.left = 1920 / 2;
    return 0;
}

static
void check_plane(const radar_t *radar, const int *i, sfVector2f *pos, int y)
{
    sfVector2f pos2;

    pos2 = sfSprite_getPosition(radar->plane[y]->sprite);
    if (radar->plane[*i]->disp == 0 && radar->plane[y]->disp == 0 && y != *i)
        if (fabsf((*pos).x - pos2.x) < ((float) 20 / 2 + (float) 20 / 2) &&
            fabsf((*pos).y - pos2.y) < ((float) 20 / 2 + (float) 20 / 2)) {
            radar->plane[*i]->disp = 1;
            radar->plane[y]->disp = 1;
        }
}

static int check_area(radar_t *radar, sfVector2f *pos, int **i)
{
    if ((*pos).x <= (float) radar->area->top_left.width && (*pos).y <=
        (float) radar->area->top_left.height)
        radar->plane[**i]->area = 1;
    if ((*pos).x >= (float) radar->area->top_right.width && (*pos).y <=
        (float) radar->area->top_right.height)
        radar->plane[**i]->area = 2;
    if ((*pos).x <= (float) radar->area->bottom_left.width && (*pos).y >=
        (float) radar->area->bottom_left.height)
        radar->plane[**i]->area = 3;
    if ((*pos).x >= (float) radar->area->top_left.width && (*pos).y >=
        (float) radar->area->top_left.height)
        radar->plane[**i]->area = 4;
    return 0;
}

static int collision(radar_t *radar, int *i)
{
    sfVector2f pos;

    assign_area(radar);
    pos = sfSprite_getPosition(radar->plane[*i]->sprite);
    check_area(radar, &pos, &i);
    pos = sfSprite_getPosition(radar->plane[*i]->sprite);
    for (int y = 0; radar->plane[y] != NULL; y += 1) {
        if (radar->plane[*i]->area == radar->plane[y]->area) {
            check_plane(radar, i, &pos, y);
        }
    }
    return 0;
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

void display_plane(radar_t *radar)
{
    for (int i = 0; radar->plane[i] != NULL; i += 1) {
        if (radar->plane[i]->disp == 0) {
            sfRenderWindow_drawSprite(radar->window, radar->plane[i]->sprite,
                NULL);
            sfRenderWindow_drawRectangleShape(radar->window,
                radar->plane[i]->rectangle, NULL);
        }
    }
}

int display_radar(radar_t *radar, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = (float)((double)time.microseconds / 1000000.0);
    sfVector2f mvt;

    sfRenderWindow_clear(radar->window, sfWhite);
    sfRenderWindow_drawSprite(radar->window, radar->map->sprite, NULL);
    for (int i = 0; radar->tower[i] != NULL; i += 1) {
        sfRenderWindow_drawSprite(radar->window, radar->tower[i]->sprite,
            NULL);
        sfRenderWindow_drawCircleShape(radar->window, radar->tower[i]->circle,
            NULL);
    }
    check_mvt_col(radar, clock, seconds, &mvt);
    display_plane(radar);
    sfRenderWindow_display(radar->window);
    return 0;
}
