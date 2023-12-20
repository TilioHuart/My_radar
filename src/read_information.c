/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** read_information.c
*/

#include "radar.h"

int fs_open_file(char const *filepath)
{
    int fd;

    if (filepath == NULL)
        return 84;
    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        close(fd);
        return 84;
    }
    return fd;
}

char *read_info(char **av)
{
    int fd = fs_open_file(av[1]);
    char buffer[1];
    char *map = NULL;
    struct stat stats;
    int i = 0;

    stat(av[1], &stats);
    map = malloc(sizeof(char) * stats.st_size + 1);
    if (map == NULL)
        return "ERROR";
    while (read(fd, buffer, 1) != 0) {
        if (buffer[0] != 0) {
            map[i] = buffer[0];
            i += 1;
        }
        map[i] = '\0';
    }
    return map;
}
