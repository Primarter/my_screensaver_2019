/*
** EPITECH PROJECT, 2019
** bootstrap_graphic
** File description:
** my_graphic_funct.h
*/

#ifndef MY_GRAPHIC_FUNCT_H_
#define MY_GRAPHIC_FUNCT_H_

sfVideoMode set_videomode(sfVideoMode mode, int width, int height, int bpp);

int handle_window(sfEvent event, sfRenderWindow* window, int s);

int my_draw_line(framebuffer_t *fb, sfVector2i p_a, sfVector2i p_b, sfColor c);

int my_draw_circle(framebuffer_t *fb, sfVector2i c, int radius, sfColor col);

void my_draw_square(framebuffer_t *fb, sfVector2i p, unsigned int s, sfColor c);

#endif