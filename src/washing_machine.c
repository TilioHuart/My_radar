/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** washing_machine.c
*/

#include "radar.h"

static void wash_info(radar_t *radar, int *i)
{
    if (radar->info[*i] != NULL)
        free(radar->info[*i]);
}

void wash_plane(const radar_t *radar)
{
    if (radar != NULL && radar->plane != NULL)
        for (int i = 0; radar->plane[i] != NULL; i += 1) {
            sfSprite_destroy(radar->plane[i]->sprite);
            sfRectangleShape_destroy(radar->plane[i]->rectangle);
            free(radar->plane[i]);
        }
}

void wash_radar(const radar_t *radar)
{
    if (radar != NULL && radar->tower != NULL)
        for (int i = 0; radar->tower[i] != NULL; i += 1) {
            sfSprite_destroy(radar->tower[i]->sprite);
            sfCircleShape_destroy(radar->tower[i]->circle);
            free(radar->tower[i]);
        }
}

void wash_final(radar_t *radar)
{
    if (radar != NULL) {
        sfTexture_destroy(radar->texture_plane);
        sfTexture_destroy(radar->texture_tower);
        sfRenderWindow_destroy(radar->window);
        free(radar);
    }
}

int washing_machine(radar_t *radar)
{
    if (radar != NULL && radar->info != NULL) {
        for (int i = 0; radar->info[i] != NULL; i += 1)
            wash_info(radar, &i);
        free(radar->info);
    }
    wash_plane(radar);
    wash_radar(radar);
    wash_final(radar);
    return 0;
}
