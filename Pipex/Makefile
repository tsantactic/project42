
NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS =	srcs/pipex.c srcs/utils.c srcs/proccess.c
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = lib
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I include -I $(LIBFT_DIR)/include

all: $(LIBFT) $(NAME)

$(LIBFT):
	cd $(LIBFT_DIR) && $(MAKE)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	cd $(LIBFT_DIR) && $(MAKE) clean
	rm -f $(OBJS)

fclean: clean
	cd $(LIBFT_DIR) && $(MAKE) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
