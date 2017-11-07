##
## Makefile for raytracer in /home/breton_y/Raytracer
##
## Made by yanis breton
## Login   <breton_y@epitech.net>
##
## Started on  Thu May  7 12:16:13 2015 yanis breton
## Last update Sun Jun  7 21:51:15 2015 Hugo Bauer
##

NAME		=	rt

SRC		=	main.c \
			calc.c \
			gere_event.c \
			load_bar.c \
			calc_delta/cone.c \
			calc_delta/cylindre.c \
			calc_delta/sphere.c \
			light/light.c \
			light/light_list.c \
			light/light_obj.c \
			light/calc_texture.c \
			light/normal.c \
			light/transparence.c \
			light/shadow.c \
			math/rotation.c \
			math/transformation.c \
			obj/intersection.c \
			obj/mesh.c \
			parsing/parse.c \
			parsing/parse_obj.c \
			parsing/parse_mesh.c \
			parsing/parse_mesh2.c \
			parsing/check_expr.c \
			utils/atouc.c \
			utils/calc_vector.c \
			utils/color_overflow.c \
			utils/get_next_line.c \
			utils/init.c \
			utils/maths.c \
			utils/my_fputs.c \
			utils/my_mod_strdup.c \
			utils/my_strcat.c \
			utils/my_strcmp.c \
			utils/my_strcpy.c \
			utils/my_strlen.c \
			utils/my_strndup.c \
			utils/my_str_realloc.c \
			utils/strlcpy.c \
			utils/str_to_wordtab.c \
			utils/put_pixel_image.c \
			utils/xmalloc.c

OBJ		=	$(SRC:.c=.o)

ifeq ($(WARNING),)
CFLAGS		+=	-Wall -Wextra #-Werror
endif

ifeq ($(DEBUG),1)
CFLAGS		+=	-g3
endif

ifeq ($(OPTI),1)
CFLAGS		+=	-O
endif

CFLAGS		+=	-ansi -pedantic
CFLAGS		+=	-lmlx -lXext -lX11
CFLAGS		+=	-lm
CFLAGS		+=	-Iinclude/

CC		=	gcc

RM		=	rm -f

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
