/*
** EPITECH PROJECT, 2023
** ok
** File description:
** ok
*/

char *my_strcpy(char *dest, char const *src)
{
    int y = 0;

    while (src[y] != '\0') {
        dest[y] = src[y];
        y += 1;
    }
    dest[y] = '\0';
    return dest;
}
