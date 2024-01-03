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
    #include "map.h"
    #include "math.h"

typedef struct radar {
    char **info;
    sfRenderWindow *window;
    sfEvent event;
    sfTexture *texture_tower;
    sfTexture *texture_plane;
    plane_t **plane;
    tower_t **tower;
    area_t *area;
    map_t *map;
} radar_t;

int radar(int ac, char **av, char **env);
int case_of_env(char **env, int *env_f);
int launcher(char **info);
int initialisation(radar_t *radar);
char **recup_information(char **av);
char *read_info(char **av);
int send_information(radar_t *radar);
int analyse_event(radar_t *game);
int setup_plane(radar_t *radar, char **info_line, int nb_plane);
int setup_radar(radar_t *radar, char **info_line, int nb_radar);
int washing_machine(radar_t *radar);
int display_radar(radar_t *radar, sfClock *clock);
int collision(radar_t *radar, int *i);

#endif
