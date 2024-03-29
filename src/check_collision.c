/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** check_collision.c
*/

#include "radar.h"

int assign_area(radar_t *radar)
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
    if ((*pos).x >= 940 && (*pos).x <= 980)
        radar->plane[**i]->line = 1;
    if ((*pos).y >= 520 && (*pos).y <= 560)
        radar->plane[**i]->line = 1;
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

void check_radar(const radar_t *radar, const int *i, sfVector2f *pos)
{
    (*pos) = sfSprite_getPosition(radar->plane[*i]->sprite);
    for (int y = 0; radar->plane[y] != NULL; y += 1) {
        if ((radar->plane[*i]->area == radar->plane[y]->area &&
            radar->plane[*i]->spawn == 0 && radar->plane[y]->spawn == 0) ||
                (radar->plane[*i]->line == 1 && radar->plane[y]->line == 1 &&
                radar->plane[*i]->spawn == 0 && radar->plane[y]->spawn == 0)) {
            check_plane(radar, i, pos, y);
        }
    }
}

int collision(radar_t *radar, int *i)
{
    sfVector2f pos;
    sfVector2f posc;
    float distancex = 0;
    float distancey = 0;
    float distance;

    pos = sfSprite_getPosition(radar->plane[*i]->sprite);
    check_area(radar, &pos, &i);
    for (int y = 0; radar->tower[y] != NULL; y += 1) {
        posc = sfCircleShape_getPosition(radar->tower[y]->circle);
        distancex = posc.x - pos.x;
        distancey = posc.y - pos.y;
        distance = sqrt(distancex * distancex + distancey * distancey);
        if (distance <= (float)radar->tower[y]->radius)
            return 0;
    }
    check_radar(radar, i, &pos);
    return 0;
}
