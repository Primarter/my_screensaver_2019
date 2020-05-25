/*
** EPITECH PROJECT, 2019
** MUL_my_screensaver_2019
** File description:
** calc_infin.c
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <math.h>
#include "include/structures.h"
#include "include/framebuffer.h"
#define z (stc.h - 60)

sfVector2i up_infin_m(sf_t stc, sfVector2i c, float a)
{
    c.x = 30 + (stc.w - 60) / 2 + (stc.w - 60) / 2 * -cos(a) * -sin(a);
    c.y = 30 + (z) / 2 + (z) / 2 * sin(a);
    return (c);
}

sfVector2i up_infin_p(sf_t stc, sfVector2i c, float a)
{
    c.x = 30 + (stc.w - 60) / 2 + (stc.w - 60) / 2 * cos(a) * -sin(a);
    c.y = 30 + (z) / 2 + (z) / 2 * sin(a);
    return (c);
}

sfVector2i side_infin_m(sf_t stc, sfVector2i c, float a)
{
    c.x = stc.w - (30 + (stc.w - 60) / 2 + (stc.w - 60) / 2 * sin(a));
    c.y = stc.h - (30 + (z) / 2 + (z) / 2 * -cos(a) * -sin(a));
    return (c);
}

sfVector2i side_infin_p(sf_t stc, sfVector2i c, float a)
{
    c.x = 30 + (stc.w - 60) / 2 + (stc.w - 60) / 2 * sin(a);
    c.y = 30 + (z) / 2 + (z) / 2 * cos(a) * -sin(a);
    return (c);
}

void set_centres3(sf_t const stc, sfVector2i *centres, saver_t sv)
{
    centres[0].y = stc.h / 4;
    centres[1].y = stc.h / 2;
    centres[2].y = stc.h * 3 / 4;
    centres[3].x = stc.w / 4;
    centres[4].x = stc.w / 2;
    centres[5].x = stc.w * 3 / 4;
    centres[0].x = stc.w / 4 + 50 * sin(sv.line);
    centres[1].x = stc.w / 2 + 50 * sin(sv.line);
    centres[2].x = stc.w * 3 / 4+ 50 * sin(sv.line);
    centres[3].y = stc.h / 4 + 50 * sin(sv.line);
    centres[4].y = stc.h / 2 + 50 * sin(sv.line);
    centres[5].y = stc.h * 3 / 4 + 50 * sin(sv.line);
}