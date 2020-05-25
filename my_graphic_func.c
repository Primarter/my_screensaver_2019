/*
** EPITECH PROJECT, 2019
** MUL_my_screensaver_2019
** File description:
** my_graphic_func.c
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Export.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include/framebuffer.h"
#include "include/structures.h"
#include "include/my.h"

int my_draw_line(framebuffer_t *fb, sfVector2i p_a, sfVector2i p_b, sfColor c);

void my_draw_rect(framebuffer_t *fb, sfVector2i p, sfVector2i s, sfColor c);

sfVideoMode set_videomode(sfVideoMode mode, int width, int height, int bpp)
{
    mode.width = width;
    mode.height = height;
    mode.bitsPerPixel = bpp;
    return mode;
}

int handle_window(sfEvent event, sfRenderWindow *window, int s)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
            sfRenderWindow_close(window);
        if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
            s += 1;
        if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue && s > 0)
            s -= 1;
    }
    return (s);
}

int manage_mouse_click(sfEvent event, sfRenderWindow *window)
{
    int y = 0;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
            sfRenderWindow_close(window);
        if (sfMouse_isButtonPressed(event.mouseButton.button) ==  sfTrue) {
            y = event.mouseButton.y;
        }
    }
    return (y);
}

void print_map(char const *filepath, sf_t *stc)
{
    sfVector2i pos = {0, 0};
    sfVector2i size = {16, 12};
    sfColor font = {130, 140, 190, 255};
    sfColor background = {20, 0, 30, 255};
    sfColor col = sfBlack;
    int fd = open(filepath, O_RDONLY);
    char res = 0;
    while (read(fd, &res, 1)) {
        if (res != '\n') {
            col = res == '1' ? font : background;
            my_draw_rect(stc->fb, pos, size, col);
            pos.y += pos.x < 1280 ? 0 : 12;
            pos.x += pos.x < 1280 ? 16 : -1280;
        } else {
            pos.x += 32;
        }
    }
    close(fd);
}

int menu(sf_t *stc)
{
    int y = 0;
    sfVector2i a = {1, stc->h / 5};
    sfVector2i b = {2, stc->h / 5};

    print_map("chiffres_map.txt", stc);
    for (int i = 1; i <= 5; i += 1) {
        a.y = stc->h / 5 * i;
        b.y = stc->h / 5 * i;
        my_draw_line(stc->fb, a, b, sfRed);
    }
    y = manage_mouse_click(stc->event, stc->win);
    for (int i = 0; i < 5; i += 1) {
        if (y > ((stc->h / 5) * (i)) && y < (stc->h / 5) * (i + 1)) {
            return (i + 1);
        }
    }
    return (0);
}