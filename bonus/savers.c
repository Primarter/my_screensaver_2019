/*
** EPITECH PROJECT, 2019
** MUL_my_screensaver_2019
** File description:
** savers.c
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

sfVector2i up_infin_m(sf_t stc, sfVector2i c, float a);

sfVector2i up_infin_p(sf_t stc, sfVector2i c, float a);

sfVector2i side_infin_m(sf_t stc, sfVector2i c, float a);

sfVector2i side_infin_p(sf_t stc, sfVector2i c, float a);

void set_centres3(sf_t const stc, sfVector2i *centres, saver_t sv);

saver_t int_to_colors(saver_t sv);

saver_t saver1(sf_t const stc, saver_t sv)
{
    int rad = 30;

    fade_fb(stc.fb, stc.w, stc.h, 20);
    my_draw_circle(stc.fb, sv.inf.centre[0], rad, sv.inf.col[0]);
    my_draw_circle(stc.fb, sv.inf.centre[1], rad, sv.inf.col[1]);
    my_draw_circle(stc.fb, sv.inf.centre[2], rad, sv.inf.col[0]);
    my_draw_circle(stc.fb, sv.inf.centre[3], rad, sv.inf.col[1]);
    sv.inf.centre[0] = side_infin_p(stc, sv.inf.centre[0], sv.inf.a);
    sv.inf.centre[2] = side_infin_m(stc, sv.inf.centre[2], sv.inf.a);
    sv.inf.centre[1] = up_infin_m(stc, sv.inf.centre[1], sv.inf.a);
    sv.inf.centre[3] = up_infin_p(stc, sv.inf.centre[3], sv.inf.a);
    sv.inf.col[0] = cos(sv.inf.a + 0.03) >= cos(sv.inf.a) ? sfBlue : sfRed;
    sv.inf.col[1] = cos(sv.inf.a + 0.03) >= cos(sv.inf.a) ? sfBlue : sfRed;
    sv.inf.a += 0.04f;
    return (sv);
}

saver_t saver2(sf_t const stc, saver_t sv)
{
    sfVector2i pt_a = {stc.w / 2, stc.h};
    sfVector2i pt_b = {stc.w / 2, stc.h / 2};
    sfVector2i pt_c = {stc.w / 2, -1};
    sfVector2i middle_a = {0, stc.h / 2};
    sfVector2i middle_b = {stc.w, stc.h / 2};

    fade_fb(stc.fb, stc.w, stc.h, 15);
    pt_b.x = (stc.w / 2) + (stc.w / 2) * sin(sv.line) - 60;
    pt_b.y = stc.h / 2;
    my_draw_line(stc.fb, pt_a, pt_b, sfGreen);
    my_draw_line(stc.fb, pt_c, pt_b, sfGreen);
    my_draw_line(stc.fb, middle_a, middle_b, sfGreen);
    sv.line += 0.1f;
    return (sv);
}

saver_t saver3(sf_t const stc, saver_t sv)
{
    sfVector2i *centres = malloc(sizeof(sfVector2i) * 6);
    sfColor orange = {255, 144, 0, 255};

    fade_fb(stc.fb, stc.w, stc.h, 40);
    set_centres3(stc, centres, sv);
    for (int i = 0; i + 1 < 6; i += 1)
        my_draw_line(stc.fb, centres[i], centres[i + 1], sfBlue);
    my_draw_line(stc.fb, centres[5], centres[0], sfBlue);
    for (int i = 0; i + 3 < 6; i += 1)
        my_draw_line(stc.fb, centres[i], centres[i + 3], sfBlue);
    for (int i = 0; i < 6; i += 1)
        my_draw_circle(stc.fb, centres[i], 20, orange);
    sv.line += 0.03f;
    return (sv);
}

saver_t saver4(sf_t const stc, saver_t sv)
{
    sfColor orange = {255, 144, 0, 255};
    sfVector2i middle = {stc.w / 2, stc.h / 2};

    fade_fb(stc.fb, stc.w, stc.h, 10);
    sv.c = orange;
    my_draw_line(stc.fb, sv.start, middle, sfBlue);
    my_draw_square(stc.fb, sv.start, 20, sv.c);
    sv.c.a *= 99 / 100;
    sv.start.x = stc.w / 2 + 100 * sin(sv.angle);
    sv.start.y = stc.h / 2 + 100 * cos(sv.angle);
    sv.angle += 10;
    return (sv);
}

saver_t saver5(sf_t const stc, saver_t sv)
{
    sfVector2i rmiddle = {rand() % (stc.w - 20) + 10, rand() % (stc.h - 20) + 10};

    sv = int_to_colors(sv);
    fade_fb(stc.fb, stc.w, stc.h, 25);
    for (int i = 0; i < rand() % 1000 + 500; i += 1) {
        my_draw_circle(stc.fb, rmiddle, rand() % 6 + 1, sv.c);
        rmiddle.x = rand() % (stc.w - 20) + 10;
        rmiddle.y = rand() % (stc.h - 20) + 10;
    }
    sv.n += 255 + 2 * 255 * 255 + 3 * 255 * 255 * 255;
    return (sv);
}