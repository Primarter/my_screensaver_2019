/*
** EPITECH PROJECT, 2019
** my_showstr
** File description:
** non
*/

void my_putchar(char c);

void convert_hexadecimal(char c)
{
    my_putchar((c / 16) + 48);
    if ((c % 16) < 10)
        my_putchar(c + 48);
    if ((c % 16) >= 10)
        my_putchar(c + 87);
}

int my_showstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if ((str[i] < 32) || (str[i] == 127))
            convert_hexadecimal(str[i]);
        else
            my_putchar(str[i]);
    }
    return (0);
}
