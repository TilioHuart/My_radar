/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** error.c
*/

#include "stdio.h"
#include "my.h"

int case_of_env(char **env, int *env_f)
{
    for (int i = 0; env[i] != NULL; i += 1) {
        if (my_strncmp(env[i], "DISPLAY=", 8) == 0)
            *env_f += 1;
        if (my_strncmp(env[i], "XAUTHORITY=", 11) == 0)
            *env_f += 1;
    }
    if (*env_f < 2)
        return 84;
    return 0;
}
