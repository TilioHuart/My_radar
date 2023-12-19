/*
** EPITECH PROJECT, 2023
** my_show_word_array.c
** File description:
** Write a function that
** displays the content of
** an array of words.
*/

#include "my.h"
#include <stdio.h>

int my_show_word_array(char *const *tab)
{
    int count = 0;

    if (tab == NULL)
        return 84;
    for (int y = 0; tab[y] != NULL; y += 1) {
        for (int i = 0; tab[y][i] != '\0'; i += 1) {
            my_putchar(tab[y][i]);
        }
        my_putchar('\n');
    }
    return 0;
}
