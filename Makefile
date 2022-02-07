# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 20:29:45 by juhur             #+#    #+#              #
#    Updated: 2022/02/07 17:34:02 by juhur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src
INC_DIR = ./include

SRCS = $(addprefix $(SRC_DIR)/, \
	main.c \
	so_long.c	\
	check_error.c	\
	print_error.c	\
	board.c	\
	board2.c	\
)

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT_AR = $(LIBFT_DIR)/libft.a

MLX_DIR = ./minilibx_opengl_20191021
MLX_AR = $(MLX_DIR)/libmlx.a

LIB_FLAG = -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

.PHONY : all
all: $(NAME)

.PHONY : clean
clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -rf $(OBJS)

.PHONY : fclean
fclean:	clean
	rm -rf $(LIBFT_AR)
	rm -rf $(MLX_AR)
	rm -rf $(NAME)

.PHONY : re
re: fclean all

$(LIBFT_AR) :
	make -C $(LIBFT_DIR)

$(MLX_AR) :
	make -C $(MLX_DIR)

%.o : %.c
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -I $(MLX_DIR) -I $(INC_DIR) -c $^ -o $@

$(NAME) : $(LIBFT_AR) $(MLX_AR) $(OBJS)
	$(CC) $(CFLAGS) $(LIB_FLAG) $^ -I $(INC_DIR) -o $@
