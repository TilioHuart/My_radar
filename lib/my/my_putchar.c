/*
** EPITECH PROJECT, 2023
** ok
** File description:
** ok
*/

#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}
