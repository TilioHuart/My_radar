/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** main.c
*/

#include "radar.h"

int main(int ac, char **av, char **env)
{
    int env_f = 0;
    int error = case_of_env(env, &env_f);
    char **info;

    if (error == 84 || ac != 2)
        return 84;
    info = recup_information(av);
    launcher(info);
    return 0;
}
