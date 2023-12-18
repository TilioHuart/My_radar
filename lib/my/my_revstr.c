/*
** EPITECH PROJECT, 2023
** ok
** File description:
** ok
*/

int my_strlen2(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i += 1);
    return i;
}

char *my_revstr(char *str)
{
    int len = my_strlen2(str);
    int swap;

    for (int i = 0; i < (len - i - 1); ++i) {
        swap = str[len - i - 1];
        str[len - i - 1] = str[i];
        str[i] = swap;
        }
    return str;
}
