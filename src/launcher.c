/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** launcher.c
*/

#include "radar.h"

int launcher(char **info)
{
    radar_t *radar;

    radar = malloc(sizeof(radar_t));
    radar->info = info;
    sfClock *clock = sfClock_create();
    send_information(radar);
    initialisation(radar);
    while (sfRenderWindow_isOpen(radar->window)) {
        display_radar(radar, clock);
        analyse_event(radar);
    }
    sfRenderWindow_close(radar->window);
    washing_machine(radar);
    return 0;
}
