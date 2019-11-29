NAME			=		libftprintf.a

HEADER			=		ftprintf.h

SRC				=		ftprintf.c

OBJ				=		${SRC:.c=.o}

FLAGS			=		-Wall -Wextra -Werror -g

%.o: %.c $(HEADER)
					gcc $(FLAGS) -c $< -o ${<:.c=.o}

all:		$(NAME)

$(NAME):	$(OBJ)
				ar rcs $(NAME) $(OBJ)

clean:
				rm -rf $(OBJ) $(OBJ_BONUS)

fclean:		clean
				rm -rf $(NAME) $(NAME).dSYM

re:		fclean all
