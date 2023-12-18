/*
** EPITECH PROJECT, 2023
** ok
** File description:
** ok
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
        i += 1;
    }
    return str;
}
