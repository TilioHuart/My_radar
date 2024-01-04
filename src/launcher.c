/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** launcher.c
*/

#include "radar.h"

static void stop_radar(radar_t *radar)
{
    int count = 0;
    int count2 = 0;

    for (int i = 0; radar->plane[i] != NULL; i += 1)
        count += 1;
    for (int i = 0; radar->plane[i] != NULL; i += 1)
        if (radar->plane[i]->disp == 1 && radar->plane[i]->spawn == 0)
            count2 += 1;
    if (count == count2)
        sfRenderWindow_close(radar->window);
}

int launcher(char **info)
{
    radar_t *radar = malloc(sizeof(radar_t));
    sfClock *clock = sfClock_create();
    int error = 0;

    radar->info = info;
    error = send_information(radar);
    if (error == 84)
        return 84;
    initialisation(radar);
    while (sfRenderWindow_isOpen(radar->window)) {
        display_radar(radar, clock);
        analyse_event(radar);
        stop_radar(radar);
    }
    sfRenderWindow_close(radar->window);
    sfClock_destroy(clock);
    washing_machine(radar);
    return 0;
}
