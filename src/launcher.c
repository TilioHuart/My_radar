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
    initialisation(radar, info);
    send_information(radar);
    while (sfRenderWindow_isOpen(radar->window))
        analyse_event(radar);
    sfRenderWindow_close(radar->window);
    washing_machine(radar);
    return 0;
}
