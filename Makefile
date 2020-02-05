NAME			=		libftprintf.a

HEADER			=		ftprintf.h

SRC				=		printf.c	\
						parser.c	\
						prints.c	\
						printnum.c	\
						utils.c

OBJ				=		${SRC:.c=.o}

FLAGS			=		-Wall -Wextra -Werror -g

%.o: %.c
					gcc $(FLAGS) -I $(HEADER) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ)
				ar rcs $(NAME) $(OBJ)

clean:
				rm -rf $(OBJ) $(OBJ_BONUS)

fclean:		clean
				rm -rf $(NAME) *.dSYM

re:			fclean all

test:		$(NAME)
				gcc $(FLAGS) test.c -o test -L. -lftprintf

.PHONY: all clean fclean re test