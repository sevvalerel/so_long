NAME = so_long
CC = cc

SRC = main.c clone_map.c error.c images_file.c maps_control.c move.c free.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

FT_PRINTF_LIB = ft_printf/libftprintf.a
LIBFT_LIB = libft/libft.a
MINILIB_LINUX = minilibx-linux/libmlx_Linux.a 

LDFLAGS = -Lminilibx-linux -Lft_printf -Llibft -lmlx -lX11 -lXext -lm
LDLIBS = $(FT_PRINTF_LIB) $(LIBFT_LIB) $(MINILIB_LINUX)

all: $(NAME)

$(NAME): $(OBJ) $(FT_PRINTF_LIB) $(LIBFT_LIB) $(MINILIB_LINUX)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS) $(LDLIBS)

$(FT_PRINTF_LIB):
	$(MAKE) -C ft_printf

$(LIBFT_LIB):
	$(MAKE) -C libft

$(MINILIB_LINUX):
	$(MAKE) -C minilibx-linux

clean:
	rm -f $(OBJ)
	$(MAKE) -C ft_printf clean
	$(MAKE) -C libft clean
	$(MAKE) -C minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ft_printf fclean
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
