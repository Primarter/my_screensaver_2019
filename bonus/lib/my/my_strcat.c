/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my_strcat
*/

#include <stdio.h>

char *my_strcat(char *dest, char const *src)
{
    int a = 0;
    int c = 0;

    while (dest[a] != '\0') {
        a++;
    }
    while (src[c] != '\0') {
        dest[a] = src[c];
        a++;
        c++;
    }
}
