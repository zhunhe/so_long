# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 20:29:45 by juhur             #+#    #+#              #
#    Updated: 2022/01/29 20:29:46 by juhur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = \
	main.c

OBJS = $(SRCS:.c=.o)

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -rf $(OBJS)

.PHONY: fclean
fclean:	clean
	rm -rf $(NAME)

.PHONY: re
re: fclean all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
