NAME			=		libftprintf.a

HEADER			=		ftprintf.h

SRC				=		ftprintf.c		\
						parser.c		\
						ftprinters.c

OBJ				=		${SRC:.c=.o}

FLAGS			=		-Wall -Wextra -Werror -g

%.o: %.c
					gcc $(FLAGS) -I $(HEADER) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ)
				make -C libft
				mv libft/libft.a ./$(NAME)
				ar rcs $(NAME) $(OBJ)

clean:
				make -C libft clean
				rm -rf $(OBJ) $(OBJ_BONUS)

fclean:		clean
				rm -rf $(NAME) *.dSYM

re:			fclean all

test:		$(NAME)
				gcc $(FLAGS) test.c -o test -L. -lftprintf

.PHONY: all clean fclean re