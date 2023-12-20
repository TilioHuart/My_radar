/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** setup_plane.c
*/

#include "radar.h"

int setup_plane(radar_t *radar, char **info_line, int nb_plane)
{
    static int i = 0;

    if (i < nb_plane) {
        radar->plane[i] = malloc(sizeof(plane_t));
        if (radar->plane[i] == NULL)
            return 84;
        radar->plane[i]->pos_i.x = my_getnbr(info_line[1]);
        radar->plane[i]->pos_i.y = my_getnbr(info_line[2]);
        radar->plane[i]->pos_f.x = my_getnbr(info_line[3]);
        radar->plane[i]->pos_f.y = my_getnbr(info_line[4]);
        radar->plane[i]->speed = my_getnbr(info_line[5]);
        radar->plane[i]->delete = my_getnbr(info_line[6]);
        i += 1;
    } else {
        radar->plane[i] = NULL;
    }
    return 0;
}
