/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** initialisation.c
*/

#include "radar.h"

static int init_tower(radar_t *radar)
{
    sfVector2f origin;
    sfVector2i mouse;
    sfVector2f size;
    sfColor color = {255, 255, 255, 0};

    radar->texture_tower = sfTexture_createFromFile("assets/tower.png", NULL);
    for (int i = 0; radar->tower[i] != NULL; i += 1) {
        sfSprite_setTexture(radar->tower[i]->sprite, radar->texture_tower,
                            sfTrue);

        sfSprite_setScale(radar->tower[i]->sprite, (sfVector2f)
            {(float)0.1, (float)0.1});
        size = sfSprite_getScale(radar->tower[i]->sprite);
        sfSprite_setOrigin(radar->tower[i]->sprite,(sfVector2f){250 , 250});
        printf("scale = %f, scale = %f\n", size.x, size.y);
        sfSprite_setPosition(radar->tower[i]->sprite, (sfVector2f)
            {(float)radar->tower[i]->pos.x, (float)radar->tower[i]->pos.y});
        origin = sfSprite_getPosition(radar->tower[i]->sprite);
        mouse = sfMouse_getPositionRenderWindow(radar->window);
        printf("mousex = %d, mousey = %d\n", mouse.x, mouse.y);
        printf("x = %f, y = %f\n", origin.x, origin.y);
        sfCircleShape_setPosition(radar->tower[i]->circle, origin);
        sfCircleShape_setOrigin(radar->tower[i]->circle, (sfVector2f){radar->tower[i]->radius, radar->tower[i]->radius});
        sfCircleShape_setFillColor(radar->tower[i]->circle, color);
        sfCircleShape_setOutlineThickness(radar->tower[i]->circle, 3);
        sfCircleShape_setOutlineColor(radar->tower[i]->circle, sfBlack);
        sfCircleShape_setRadius(radar->tower[i]->circle, (float)radar->tower[i]->radius);
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
    radar->map->sprite = sfSprite_create();
    sfSprite_setTexture(radar->map->sprite, radar->map->texture, sfTrue);
    init_tower(radar);
    return 0;
}
