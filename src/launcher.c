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
    sfVideoMode VideoMode = {1920, 1080, 32};

    radar = malloc(sizeof(radar_t));
    radar->window = sfRenderWindow_create(VideoMode, "My_Radar",
        sfDefaultStyle, NULL);
    radar->info = info;
    my_show_word_array(radar->info);
    while (sfRenderWindow_isOpen(radar->window))
        analyse_event(radar);
    sfRenderWindow_close(radar->window);
    send_information(radar);
    free(radar->info);
    sfRenderWindow_destroy(radar->window);
    free(radar);
    return 0;
}
