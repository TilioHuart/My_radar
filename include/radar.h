/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** radar.h
*/

#ifndef RADAR_H_
    #define RADAR_H_

    #include "SFML/Graphics.h"
    #include "SFML/Window.h"
    #include "SFML/System.h"
    #include "SFML/System/Clock.h"
    #include "stdio.h"
    #include "stdlib.h"
    #include "window.h"
    #include "my.h"
    #include "fcntl.h"
    #include "unistd.h"
    #include "sys/stat.h"

typedef struct radar {
    char **info;
    sfRenderWindow *window;
    plane_t plane;
} radar_t;

int case_of_env(char **env, int *env_f);
int launcher(char **info);
char **recup_information(char **av);
char *read_info(char **av);

#endif
