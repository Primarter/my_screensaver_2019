/*
** EPITECH PROJECT, 2019
** bootstrap_graphic
** File description:
** structures.h
*/

#ifndef STRUCTURES_H_
#define STRUCTURESS_H_
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include "framebuffer.h"

typedef struct sf_s {
    int w;
    int h;
    sfVideoMode mode;
    sfRenderWindow *win;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2i position_square;
    sfVector2i position_line;
    sfEvent event;
    framebuffer_t *fb;
} sf_t;

typedef struct infin_s {
    float a;
    sfVector2i *centre;
    sfColor *col;
} infin_t;

typedef struct savers_s {
    infin_t inf;
    float line;
    sfColor c;
    sfVector2i start;
    float angle;
    int n;
} saver_t;

#endif