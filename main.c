/*
** EPITECH PROJECT, 2019
** bootstrap_graphic
** File description:
** first_graphic.c
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "include/framebuffer.h"
#include "include/my_graphic_funct.h"
#include "include/structures.h"
#include "include/my.h"

sf_t struct_def(int width, int height);

sfVector2i up_infin_m(sf_t stc, sfVector2i c, float a);

sfVector2i up_infin_p(sf_t stc, sfVector2i c, float a);

sfVector2i side_infin_m(sf_t stc, sfVector2i c, float a);

sfVector2i side_infin_p(sf_t stc, sfVector2i c, float a);

saver_t saver1(sf_t const stc, saver_t sv);

saver_t saver2(sf_t const stc, saver_t sv);

saver_t saver3(sf_t const stc, saver_t sv);

saver_t saver4(sf_t const stc, saver_t sv);

saver_t saver5(sf_t const stc, saver_t sv);

int menu(sf_t *stc);

void disp_help(char c)
{
    if (c == 'h') {
        my_printf("animation rendering in a CSFML window.\n\nUSAGE\n");
        my_printf(" ./my_screensaver [OPTIONS] animation_id\n animation_id");
        my_printf("\t  ID of the animation to process (between 1 and 2).\n\n");
        my_printf("OPTIONS\n -d\t\t  print the description of all the ");
        my_printf("animations and quit.\n -t\t\t  print the usage and quit.");
        my_printf("\n\nUSER INTERACTIONS\n LEFT_ARROW\t  switch to the");
        my_printf(" previous animation.\n RIGHT_ARROW\t  switch to the next");
        my_printf(" animation.\n");
    } else if (c == 'd') {
        my_printf("1: fading circles describing a shamrock and ");
        my_printf("changing colors.\n2: depiction of 2 vanishing points");
        my_printf("perspective Matrix-styled with fading lines\n3: parallel ");
        my_printf("lineswith circles on intersection, moving\n4: squares mov");
        my_printf("ing on a circle with random lines drawn at random angle\n");
        my_printf("5: random dots on the screen fading and popping randomly");
    }
}

int error_treatment(int ac, sf_t stc)
{
    if (!stc.win)
        return EXIT_FAILURE;
    if (!stc.texture)
        return EXIT_FAILURE;
    if (ac > 2) {
        write(2, "Please enter precisely 1 argument\n", 35);
        return (84);
    }
    return (0);
}

static sfVector2i centre[4] =
{
    {1280 / 2, 720 / 2},
    {1280 / 2, 720 / 2},
    {1280 / 2, 720 / 2},
    {1280 / 2, 720 / 2},
};

saver_t (*saver[5])(sf_t const stc, saver_t sv);

saver_t choose_display(int s, sf_t stc, saver_t sv)
{
    saver[0] = &saver1;
    saver[1] = &saver2;
    saver[2] = &saver3;
    saver[3] = &saver4;
    saver[4] = &saver5;
    sv = saver[s % 5](stc, sv);
    return (sv);
}

void display_funct(sf_t stc, int s)
{
    int h = stc.h;
    int w = stc.w;
    int status = 0;
    sfColor col[2] = {sfRed, sfBlue};
    saver_t saver_values = {{0, centre, col}, 0, sfRed, {w / 2, h / 2}, 0, 0};

    sfSprite_setTexture(stc.sprite, stc.texture, sfTrue);
    sfRenderWindow_setFramerateLimit(stc.win, 60);
    while (sfRenderWindow_isOpen(stc.win)) {
        if (status == 0) {
            status = menu(&stc);
            s = status - 1;
        } else {
            fade_fb(stc.fb, stc.w, stc.h, 255);
            s = handle_window(stc.event, stc.win, s);
            saver_values = choose_display(s, stc, saver_values);
        }
        sfTexture_updateFromPixels(stc.texture, stc.fb->pixels, w, h, 0, 0);
        sfRenderWindow_drawSprite(stc.win, stc.sprite, NULL);
        sfRenderWindow_display(stc.win);
    }
}

int main(int ac, char **av)
{
    sf_t stc = struct_def(1280, 720);
    int s = 0;

    if (error_treatment(ac, stc) != 0)
        return (84);
    if (ac != 1) {
        if (my_strcmp(av[1], "-h") == 0 || my_strcmp(av[1], "-d") == 0) {
            disp_help(av[1][1]);
            return (0);
        }
        s = my_getnbr(av[1]) - 1;
    }
    if (s < 0) {
        write(2, "Please enter only a number (1 or 2) or -h for help\n", 52);
        return (84);
    }
    display_funct(stc, s);
    sfRenderWindow_destroy(stc.win);
    return (0);
}