/*
** EPITECH PROJECT, 2023
** ok
** File description:
** ok
*/

#include <unistd.h>

int len(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i += 1);
    return i;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int y = 0;
    int le = len(src);

    if (n > le) {
        while (n != 0) {
            dest[y] = src[y];
            y += 1;
            n -= 1;
        }
        dest[y] = '\0';
    } else {
        while (n != 0) {
            dest[y] = src[y];
            y += 1;
            n -= 1;
        }
    }
    return dest;
}
