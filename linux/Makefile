# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 11:30:26 by rkaufman          #+#    #+#              #
#    Updated: 2022/03/08 10:59:39 by rkaufman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=	fdf
NAME_BONUS			:=	
LIBFT_TOOLS_LIB		:=	libft_tools.a
LIBFT_TOOLS_PATH	:=	libft_tools
LIBFT_PRINTF_LIB	:=	libft_printf.a
LIBFT_PRINTF_PATH	:=	libft_printf

LIB_PATH			:=	./
MLX_PATH			:=	minilibx-linux
MLX_LIB				:=	mlx_Linux

CC					:=	gcc
HEADERFILE			:=	fdf.h

SRC_LIB				:=	

SRC			:=	ft_fdf.c \
				ft_engine.c \
				ft_lines0.c \
				ft_lines1.c \
				ft_math.c \
				ft_rotations.c \
				ft_pixel.c \
				ft_key0.c \
				ft_key1.c \
				ft_file.c \
				ft_string.c \
				ft_map_array.c \
				ft_grafic.c \
				ft_display_info.c \
				ft_error.c \
				ft_error_map.c \
				ft_memory_map.c \
				ft_geometry.c \
				ft_color.c

SRC_BONUS	:=	

OBJ			:=	$(SRC:%.c=%.o)

CFLAGS		:=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): makelibft $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_PRINTF_PATH) -lft_printf -L$(LIBFT_TOOLS_PATH) -lft_tools -L$(MLX_PATH) -l$(MLX_LIB) -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -O3 -c $< -o $@

makelibft:
	make -C $(LIBFT_TOOLS_PATH)
	make -C $(LIBFT_PRINTF_PATH)

clean: cleanlibft
	rm -f $(OBJ)

cleanlibft:
	make -C $(LIBFT_TOOLS_PATH) clean
	make -C $(LIBFT_PRINTF_PATH) clean

fclean: fcleanlibft clean
	rm -f $(NAME)

fcleanlibft:
	make -C $(LIBFT_TOOLS_PATH) fclean
	make -C $(LIBFT_PRINTF_PATH) fclean

re: fclean all

relibft:
	make -C $(LIBFT_TOOLS_PATH) re
	make -C $(LIBFT_PRINTF_PATH) re

norminette:
	norminette -R CheckForbiddenSourceHeader $(SRC) $(HEADERFILE)
	make -C $(LIBFT_TOOLS_PATH) norminette
	make -C $(LIBFT_PRINTF_PATH) norminette

git:
	git add *

.PHONY: clean fclean re fcleanlibft cleanlibft relibft