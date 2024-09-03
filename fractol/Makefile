
NAME = fractol
NAME_B = fractol_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS =	srcs/fractol.c srcs/fractol_error.c srcs/fractol_utils.c \
		srcs/fractol_utils_sup.c srcs/maths.c srcs/events_utils.c srcs/check_values.c

SRCS_BONUS =	srcs/bonus/fractol_bonus.c srcs/bonus/fractol_error_bonus.c srcs/bonus/fractol_utils_bonus.c \
				srcs/bonus/fractol_utils_sup_bonus.c srcs/bonus/maths_bonus.c srcs/bonus/events_utils_bonus.c \
				srcs/bonus/check_values_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
LIBFT_DIR = lib/
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = minilibx-linux/
MLX = $(MLX_DIR)/libmlx.a
INCLUDES =	-I include \
			-I $(LIBFT_DIR)/include \
			-I /usr/include -I $(MLX_DIR)

all: $(LIBFT) $(MLX) $(NAME)
bonus : $(OBJS_BONUS) $(LIBFT) $(MLX) $(NAME_B)

$(LIBFT):
	cd $(LIBFT_DIR) && $(MAKE)

$(MLX):
	cd $(MLX_DIR) && $(MAKE)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
$(NAME_B): $(OBJS_BONUS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX) -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME_B)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -Imlx_linux -O2 -c $< -o $@

clean:
	cd $(LIBFT_DIR) && $(MAKE) clean
	cd $(MLX_DIR) && $(MAKE) clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	cd $(LIBFT_DIR) && $(MAKE) fclean
	rm -f $(NAME)
	rm -f $(NAME_B)

re: fclean all

.PHONY: all clean fclean re bonus
