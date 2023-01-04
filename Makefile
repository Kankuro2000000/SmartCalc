NAME		=	smart_calc

SRC			=	main.c linked_list.c checkers.c add_func.c

HEADER		=	smart_calc.h

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

GTK			=	`pkg-config --cflags gtk+-3.0`

GTK2		=	`pkg-config --libs gtk+-3.0`

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) -g -o $(NAME) $(HEADER) $(SRC) -lm

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re