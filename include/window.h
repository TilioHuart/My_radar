/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** window.h
*/

#ifndef WINDOW_H_
    #define WINDOW_H_

typedef struct plane {
    sfVector2i pos_i;
    sfVector2i pos_f;
    int speed;
    int delete;
    sfSprite *sprite;
    sfRectangleShape *rectangle;
    sfVector2f vecteur;
    int lenght;
    sfVector2f vecteurnormal;
    int disp;
    int area;
    int hitbox;
    int disp_s;
} plane_t;

typedef struct tower {
    sfVector2i pos;
    int radius;
    sfSprite *sprite;
    sfCircleShape *circle;
    int hitbox;
    int disp_s;
} tower_t;

typedef struct area {
    sfIntRect top_left;
    sfIntRect top_right;
    sfIntRect bottom_left;
    sfIntRect bottom_right;
} area_t;

#endif
