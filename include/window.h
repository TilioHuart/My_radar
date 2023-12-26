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
} plane_t;

typedef struct tower {
    sfVector2i pos;
    int radius;
    sfSprite *sprite;
    sfCircleShape *circle;
} tower_t;

#endif
