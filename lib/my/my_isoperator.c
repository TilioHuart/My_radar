/*
** EPITECH PROJECT, 2023
** ok
** File description:
** ok
*/

int my_isoperator(char c)
{
    if (c == 42 || c == 43 || c == 45 || c == 47 || c == 37) {
        return 0;
    } else {
        return 1;
    }
}
