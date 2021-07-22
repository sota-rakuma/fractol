# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 15:16:06 by srakuma           #+#    #+#              #
#    Updated: 2021/07/20 12:34:16 by srakuma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = mlx-linux
MLX_LIB = -L./$(MLX_DIR) -lmlx
LIBS = -lXext -lX11 -lm -lz
SRCS = color.c\
	fractol_2.c\
	hooks_1.c\
	main.c\
	calculate.c\
	fractol_1.c\
	fractol_3.c\
	fractol_utils_1.c\
	fractol_utils_2.c\
	hooks_2.c
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
NAME = fractol

all: $(NAME)

$(NAME) : $(MLX_DIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_LIB) $(LIBS)

bonus : all

$(MLX_DIR):
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR)
	make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -I $(MLX_DIR) -c $< -o $@

-include $(DEPS)

clean :
	rm -f $(OBJS) $(DEPS)

fclean : clean
	rm -fR $(NAME) $(MLX_DIR)

re : fclean all

.PHONY: all bonus clean fclean re