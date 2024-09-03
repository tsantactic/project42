# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/31 17:16:46 by sandriam          #+#    #+#              #
#    Updated: 2024/06/03 16:27:51 by sandriam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ../include
AR = ar -rcs
RM = rm -f

SRCS = srcs/ft_printf.c \
       srcs/ft_printf_dec.c \
       srcs/ft_printf_str.c \
       srcs/ft_printf_hex.c \
       srcs/ft_printf_unsigned.c \
       srcs/ft_printf_ptr.c \
       srcs/ft_printf_percent.c

OBJS = $(SRCS:srcs/%.c=%.o)

%.o:srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@
       
$(NAME): $(OBJS)
		${AR} ${NAME} ${OBJS}

all: ${NAME}

clean:
	$(RM) $(OBJS)
       
fclean: clean
	$(RM) $(NAME)

re: fclean all
