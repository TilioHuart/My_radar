/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** radar.c
*/

#include "radar.h"

int radar(int ac, char **av, char **env)
{
    int env_f = 0;
    int error = case_of_env(env, &env_f);
    char **info;

    if (error == 84 || ac != 2)
        return 84;
    info = recup_information(av);
    if (info == NULL)
        return 84;
    launcher(info);
    return 0;
}
