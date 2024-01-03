/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** hitbox_event.c
*/

#include "radar.h"

int check_hitbox(radar_t *radar)
{
    if (sfKeyboard_isKeyPressed(sfKeyL)) {
        for (int i = 0; radar->plane[i] != NULL; i += 1)
            radar->plane[i]->hitbox *= (-1);
        for (int i = 0; radar->tower[i] != NULL; i += 1)
            radar->tower[i]->hitbox *= (-1);
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        for (int i = 0; radar->plane[i] != NULL; i += 1)
            radar->plane[i]->disp_s *= (-1);
        for (int i = 0; radar->tower[i] != NULL; i += 1)
            radar->tower[i]->disp_s *= (-1);
    }
    return 0;
}
