# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 12:03:27 by seowokim          #+#    #+#              #
#    Updated: 2023/03/03 15:28:12 by seowokim         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS_DIR = ./srcs
ERROR_DIR = error
GNL_DIR = gnl
PARSING_DIR = parsing
EXECUTE_DIR = execute

HEADER_DIR = ./includes/
OBJS_DIR = ./objs

MLX_DIR = ./mlx
LIBFT_DIR = ./libft

vpath %.c $(SRCS_DIR)

SRCS = \
main.c \
$(ERROR_DIR)/error_handling.c \
$(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c \
$(PARSING_DIR)/initialize_data.c $(PARSING_DIR)/set_data_map.c $(PARSING_DIR)/set_data_map_utils.c $(PARSING_DIR)/set_data_map_utils2.c $(PARSING_DIR)/parsing_utils.c $(PARSING_DIR)/validate_map_data.c $(PARSING_DIR)/validate_map_data_utils.c \
$(EXECUTE_DIR)/initialize_info.c $(EXECUTE_DIR)/initialize_info_utils.c $(EXECUTE_DIR)/calc.c $(EXECUTE_DIR)/key.c $(EXECUTE_DIR)/key_event.c $(EXECUTE_DIR)/render.c \

OBJ = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

OBJS = $(addprefix $(OBJS_DIR)/, $(OBJ))
CC = cc

LIBFT = -L./libft/ -lft
MLX = -L./mlx -lmlx

CFLAGS = -Wall -Wextra -Werror -MMD
MLX_FLAGS = -framework OpenGL -framework AppKit
RM = rm -f
RMDIR = rm -rf

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "\t===== Compiling :\033[0;33m" $@ "\033[0;37m===="
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) -I $(HEADER_DIR) -I $(LIBFT_DIR)/ -I $(MLX_DIR)/ $(MLX) $(LIBFT) $(OBJS) -o $@
	@echo "\t==\033[0;33m" $@ "\033[0;37mHAS BEEN CREATED =="

$(OBJS_DIR)/%.o : %.c
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/$(ERROR_DIR) $(OBJS_DIR)/$(GNL_DIR) $(OBJS_DIR)/$(PARSING_DIR) $(OBJS_DIR)/$(EXECUTE_DIR)
	@$(CC) $(CFLAGS) -I $(HEADER_DIR) -I $(LIBFT_DIR)/ -I $(MLX_DIR)/ -c $< -o $@

clean :
	@echo "REMOVE OBJECTIVE FILES"
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@$(RMDIR) $(OBJS_DIR)

fclean : clean
	@echo "REMOVE $(NAME)"
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re

-include $(DEPS)
