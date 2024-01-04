/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** initialisation.c
*/

#include "radar.h"

static int set_towercircle(radar_t *radar, int *i)
{
    sfVector2f origin;
    sfColor color = {255, 255, 255, 0};

    origin = sfSprite_getPosition(radar->tower[*i]->sprite);
    sfCircleShape_setPosition(radar->tower[*i]->circle, origin);
    sfCircleShape_setOrigin(radar->tower[*i]->circle, (sfVector2f)
        {(float)radar->tower[*i]->radius, (float)radar->tower[*i]->radius});
    sfCircleShape_setFillColor(radar->tower[*i]->circle, color);
    sfCircleShape_setOutlineThickness(radar->tower[*i]->circle, 3);
    sfCircleShape_setOutlineColor(radar->tower[*i]->circle, sfBlack);
    sfCircleShape_setRadius(radar->tower[*i]->circle,
        (float)radar->tower[*i]->radius);
    return 0;
}

static int init_tower(radar_t *radar)
{
    radar->texture_tower = sfTexture_createFromFile("assets/tower.png", NULL);
    if (radar->texture_tower == NULL)
        return 84;
    for (int i = 0; radar->tower[i] != NULL; i += 1) {
        sfSprite_setTexture(radar->tower[i]->sprite, radar->texture_tower,
                            sfTrue);
        sfSprite_setScale(radar->tower[i]->sprite, (sfVector2f)
            {(float)0.1, (float)0.1});
        sfSprite_setOrigin(radar->tower[i]->sprite, (sfVector2f){250, 250});
        sfSprite_setPosition(radar->tower[i]->sprite, (sfVector2f)
            {(float)radar->tower[i]->pos.x, (float)radar->tower[i]->pos.y});
        set_towercircle(radar, &i);
    }
    return 0;
}

static int init_planerectangle(radar_t *radar, int *i)
{
    sfVector2f origin;
    sfColor color = {0, 0, 0, 0};

    origin = sfSprite_getPosition(radar->plane[*i]->sprite);
    sfRectangleShape_setPosition(radar->plane[*i]->rectangle, origin);
    sfRectangleShape_setOrigin(radar->plane[*i]->rectangle, (sfVector2f)
        {10, 10});
    sfRectangleShape_setFillColor(radar->plane[*i]->rectangle, color);
    sfRectangleShape_setOutlineThickness(radar->plane[*i]->rectangle, 3);
    sfRectangleShape_setOutlineColor(radar->plane[*i]->rectangle, sfBlack);
    sfRectangleShape_setSize(radar->plane[*i]->rectangle, (sfVector2f)
        {20, 20});
    return 0;
}

static void init_plane_mvt(const radar_t *radar, int i)
{
    radar->plane[i]->vecteur.x = (float)radar->plane[i]->pos_f.x -
        (float)radar->plane[i]->pos_i.x;
    radar->plane[i]->vecteur.y = (float)radar->plane[i]->pos_f.y -
        (float)radar->plane[i]->pos_i.y;
    radar->plane[i]->lenght = sqrt(radar->plane[i]->vecteur.x *
        radar->plane[i]->vecteur.x + radar->plane[i]->vecteur.y *
        radar->plane[i]->vecteur.y);
    radar->plane[i]->vecteurnormal.x = radar->plane[i]->vecteur.x /
        (float)radar->plane[i]->lenght;
    radar->plane[i]->vecteurnormal.y = radar->plane[i]->vecteur.y /
        (float)radar->plane[i]->lenght;
    radar->plane[i]->disp = 0;
}

static int init_plane(radar_t *radar)
{
    radar->texture_plane = sfTexture_createFromFile("assets/plane.png", NULL);
    if (radar->texture_plane == NULL)
        return 84;
    for (int i = 0; radar->plane[i] != NULL; i += 1) {
        sfSprite_setTexture(radar->plane[i]->sprite, radar->texture_plane,
                            sfTrue);
        sfSprite_setScale(radar->plane[i]->sprite, (sfVector2f)
            {(float)0.05, (float)0.05});
        sfSprite_setOrigin(radar->plane[i]->sprite, (sfVector2f){250, 250});
        sfSprite_setPosition(radar->plane[i]->sprite, (sfVector2f)
            {(float)radar->plane[i]->pos_i.x,
            (float)radar->plane[i]->pos_i.y});
        init_plane_mvt(radar, i);
        init_planerectangle(radar, &i);
    }
    return 0;
}

int initialisation(radar_t *radar)
{
    sfVideoMode VideoMode = {1920, 1080, 32};

    assign_area(radar);
    radar->map = malloc(sizeof(map_t));
    radar->window = sfRenderWindow_create(VideoMode, "My_Radar",
        sfDefaultStyle, NULL);
    radar->map->texture = sfTexture_createFromFile("assets/map2.jpg", NULL);
    radar->map->sprite = sfSprite_create();
    sfSprite_setTexture(radar->map->sprite, radar->map->texture, sfTrue);
    init_tower(radar);
    init_plane(radar);
    if (radar->map->texture == NULL || radar->texture_tower == NULL ||
        radar->texture_plane == NULL)
        return 84;
    return 0;
}
