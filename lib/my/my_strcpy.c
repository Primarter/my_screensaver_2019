/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** copy a string to another location
*/

char *my_strcpy(char *dest, char const *src)
{
    int c = 0;

    while (src[c] != '\0') {
        dest[c] = src[c];
        c++;
    }
    return (dest);
}
