/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** analyse_event.c
*/

#include "radar.h"

int analyse_event(radar_t *game)
{
    sfRenderWindow_pollEvent(game->window, &game->event);
    switch (game->event.type) {
        case sfEvtClosed:
            sfRenderWindow_close(game->window);
            break;
        default:
            break;
    }
    return 0;
}
