NAME= libftprintf.a
SRC= ft_printf.c ft_functions.c ft_putptr.c
CFLAGS= -Wall -Wextra -Werror

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -r $(NAME) $(OBJ)
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME) $(OBJ)
re: clean all
.PHONY: all clean fclean re