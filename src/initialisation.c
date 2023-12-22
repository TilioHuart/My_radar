/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** initialisation.c
*/

#include "radar.h"

static int init_tower(radar_t *radar)
{
    radar->texture_tower = sfTexture_createFromFile("assets/tower.png", NULL);
    for (int i = 0; radar->tower[i] != NULL; i += 1) {
        sfSprite_setTexture(radar->tower[i]->sprite, radar->texture_tower,
                            sfTrue);
        sfSprite_setOrigin(radar->tower[i]->sprite, (sfVector2f) {250, 250});
        sfSprite_setScale(radar->tower[i]->sprite, (sfVector2f)
            {(float)0.1, (float)0.1});
        sfSprite_setPosition(radar->tower[i]->sprite, (sfVector2f)
            {(float)radar->tower[i]->pos.x, (float)radar->tower[i]->pos.y});
    }
    return 0;
}

int initialisation(radar_t *radar)
{
    sfVideoMode VideoMode = {1920, 1080, 32};

    radar->map = malloc(sizeof(map_t));
    radar->window = sfRenderWindow_create(VideoMode, "My_Radar",
        sfDefaultStyle, NULL);
    radar->map->texture = sfTexture_createFromFile("assets/map2.jpg", NULL);
    radar->map->sprite =sfSprite_create();
    sfSprite_setTexture(radar->map->sprite, radar->map->texture, sfTrue);
    init_tower(radar);
    return 0;
}
