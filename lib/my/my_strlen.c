/*
** EPITECH PROJECT, 2023
** ok
** File description:
** ok
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i += 1);
    return i;
}
