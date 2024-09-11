NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS =	srcs/push_swap.c srcs/ft_withqm.c srcs/utils.c srcs/sort.c \
		srcs/instructions.c srcs/instructions_utils.c\
		srcs/sort_three.c srcs/sort_utils.c srcs/sort_utils_more.c\
		srcs/sort_more.c srcs/radix.c srcs/radix_utils.c srcs/instruction_radix.c
OBJS = $(SRCS:.c=.o)
FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I include -I $(FT_PRINTF_DIR)/include -I $(LIBFT_DIR)/include

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(FT_PRINTF):
	cd $(FT_PRINTF_DIR) && $(MAKE)

$(LIBFT):
	cd $(LIBFT_DIR) && $(MAKE)

$(NAME): $(OBJS) $(FT_PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	cd $(FT_PRINTF_DIR) && $(MAKE) clean
	cd $(LIBFT_DIR) && $(MAKE) clean
	rm -f $(OBJS)

fclean: clean
	cd $(FT_PRINTF_DIR) && $(MAKE) fclean
	cd $(LIBFT_DIR) && $(MAKE) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
