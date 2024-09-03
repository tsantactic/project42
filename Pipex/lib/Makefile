NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f

SRCS = ft_strncmp.c ft_strjoin.c ft_split.c ft_putstr_fd.c ft_strlen.c

OBJS = ${SRCS:.c=.o}

$(NAME): $(OBJS)
		${AR} ${NAME} ${OBJS}
all: ${NAME}
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY:all clean fclean re
