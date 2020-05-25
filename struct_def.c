/*
** EPITECH PROJECT, 2019
** MUL_my_screensaver_2019
** File description:
** struct_def.c
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include "include/framebuffer.h"
#include "include/my_graphic_funct.h"
#include "include/structures.h"
#include "include/my.h"

sf_t struct_def(int width, int height)
{
    sf_t stc;

    stc.h = height;
    stc.w = width;
    stc.mode = set_videomode(stc.mode, width, height, 32);
    stc.win = sfRenderWindow_create(stc.mode, "win", sfResize | sfClose, NULL);
    stc.fb = framebuffer_create(width, height);
    stc.texture = sfTexture_create(width, height);
    stc.sprite = sfSprite_create();
    stc.position_square.x = 100;
    stc.position_square.y = 100;
    return stc;
}