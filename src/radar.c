/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** radar.c
*/

#include "radar.h"

static void display_message(void)
{
    my_printf("-h\n");
}

static int check_h(char **av)
{
    if (av[1][1] == 'h' && av[1][2] == '\0')
        display_message();
    return 0;
}

int radar(int ac, char **av, char **env)
{
    int env_f = 0;
    int error = case_of_env(env, &env_f);
    char **info;

    if (error == 84 || ac != 2)
        return 84;
    if (av[1][0] == '-') {
        check_h(av);
        return 0;
    }
    info = recup_information(av);
    if (info == NULL) {
        write(1, "Incorrect script\n", 17);
        return 84;
    }
    error = launcher(info);
    if (error == 84)
        return 84;
    return 0;
}
