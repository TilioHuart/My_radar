/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** main.c
*/

#include "radar.h"

int main(int ac, char **av, char **env)
{
    if (radar(ac, av, env) == 84) {
        write(2, "ERROR\n", 6);
        return 84;
    }
    return 0;
}
