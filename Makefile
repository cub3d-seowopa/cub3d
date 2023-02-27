# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 00:09:27 by chanwopa          #+#    #+#              #
#    Updated: 2023/02/27 20:59:37 by chanwopa         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra

LIBFT_DIR	=	libft
LIBFT_LIB	=	libft/libft.a

MLX_DIR		=	mlx
MLX_LIB		=	mlx/libmlx.a

LIB			=	$(MLX_LIB) $(LIBFT_LIB)

SRCS		=	main.c \
				calc.c \
				key_press.c \
				texture.c

OBJS		=	$(SRCS:.c=.o)

all	: $(NAME)

%.o	: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIB) :
	make all -C $(MLX_DIR)
	make all -C $(LIBFT_DIR)

$(NAME) : $(LIB) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) -framework OpenGL -framework Appkit

clean :
	make clean -C $(MLX_DIR)
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJS)

fclean : clean
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
