# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 11:24:52 by juhur             #+#    #+#              #
#    Updated: 2022/02/13 16:45:49 by juhur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = \
	ft_strlen.c \
	ft_strcmp.c	\
	ft_strlcat.c	\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

$(NAME): $(OBJS)
	ar rcs $@ $^

.PHONY : all, clean, fclean, re
