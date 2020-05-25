##
## EPITECH PROJECT, 2019
## makefile infin_add
## File description:
## compile src, lib, tests, etc
##

SRC	=	main.c				\
		calc_traj.c			\
		framebuffer.c		\
		savers.c			\
		my_graphic_func.c	\
		struct_def.c		\
		my_draw_func.c		\
		colors.c

CFLAGS = -W -Wall -Wextra -g3 -lm -lcsfml-graphics -lcsfml-window

OBJ	=	$(SRC:.c=.o)

OBJ_TEST	=	$(SRC_TEST:.c=.o)

NAME	=	my_screensaver

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my
	gcc $(OBJ) -o $(NAME) $(CFLAGS) libmy.a
	find -name "*.o" -type f -delete
clean:
	rm -f $(OBJ)
fclean:	clean
	rm -f $(NAME)
	find -type f -name libmy.a -delete
	find -type f -name *.o -delete
	find -type f -name unit_tests -delete
re:	fclean all