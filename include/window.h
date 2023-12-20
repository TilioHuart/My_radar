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
} plane_t;

#endif
