/*
** EPITECH PROJECT, 2023
** ok
** File description:
** ok
*/

#include <unistd.h>

int my_isneg(int n)
{
    if (n < 0) {
        write(1, "N", 1);
    }
    if (n >= 0) {
        write(1, "P", 1);
    }
    write(1, "\n", 1);
}
