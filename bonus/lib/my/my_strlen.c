/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** give array length
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i])
        i += 1;
    return i;
}
