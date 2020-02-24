# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trifflet <trifflet@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 14:15:23 by trifflet          #+#    #+#              #
#    Updated: 2020/02/20 17:02:41 by trifflet         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


NAME		=	Cub3D

HEADERS_DIR	=	header
HEADERS		=	mlx.h

LIBS		=	lib/libmlx.a		\
				lib/ftprintf.a	\
				lib/get_next_line.a

SRC_DIR		=	src

SRC_FILES	=	main.c					\
				startup.c				\
				hooker.c				\
				render.c				\
				parse.c					\
				time.c

OBJ_DIR		=	obj
OBJ_FILES	= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRC			=	$(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJ			=	$(OBJ_FILES)

FLAGS		=	-g3 -Wall -Wextra -Werror $(DEBUG) -framework OpenGL -framework AppKit

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
				gcc -g3 -Wall -Wextra -Werror -I $(HEADERS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C printf && mv printf/libftprintf.a lib/ftprintf.a
			make -C get_next_line && mv get_next_line/get_next_line.a lib/
			gcc $(FLAGS) $(OBJ) -I $(HEADERS) $(LIBS) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:		fclean all

norme:
	@norminette $(addprefix $(SRC_DIR)/, $(SRC_FILES))

.PHONY: all, clean, fclean, re, norme
