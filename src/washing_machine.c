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

int washing_machine(radar_t *radar)
{
    if (radar != NULL && radar->info != NULL) {
        for (int i = 0; radar->info[i] != NULL; i += 1)
            wash_info(radar, &i);
        free(radar->info);
    }
    if (radar != NULL) {
        sfRenderWindow_destroy(radar->window);
        free(radar);
    }
    return 0;
}
