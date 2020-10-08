# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mg <mg@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 14:40:16 by mgiraldo          #+#    #+#              #
#    Updated: 2020/10/07 21:58:29 by mg               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# 	gcc cub*.c
#	-L ft_printf -lftprintf
#	-L gnl -lgnl 
#	-L libft -lft 
#	-L minilibx-linux -lmlx
#	-lXext -lX11 -lbsd -lm

# GAME
GAME=cub3D

#Source
SRC=cub3d*.c

#Object
OBJ=${SRC:.c=.o}

#Include
INC=-I ./ -I ./libft -I ./ft_printf -I ./gnl

#FLAGS=-Wall -Wextra -Werror
FLAGS=-Wall -Wextra -Werror -g

#ft_printf libary link
PRINTF=-L ft_printf -lftprintf

#getnextline libary link
GNL=-L gnl -lgnl

#libft libary link
LIBFT=-L libft -lft

#mlx libary link
MLX=-I minilibx -L minilibx-linux -lmlx 

#Additional System libaries
SYS=-lXext -lX11 -lbsd -lm

all:$(GAME)

$(GAME):
	@make -C ./libft
	@make -C ./ft_printf
	@make -C ./gnl
	@make -C ./minilibx-linux
	gcc ${FLAGS} ${SRC} ${PRINTF} ${GNL} ${LIBFT} ${MLX} ${SYS} -o ${GAME}

#mlx does not have a clean equivalent
#mlx clean behaves similar to fclean 
clean:
	@/bin/rm -f $(OBJ)
	@make clean -C ./libft
	@make clean -C ./ft_printf
	@make clean -C ./gnl
	
#mlx clean behaves similar to fclean 
fclean: clean
	@/bin/rm -f $(GAME)
	@make fclean -C ./libft
	@make fclean -C ./ft_printf
	@make fclean -C ./gnl
	@make clean -C ./minilibx-linux

re: fclean all

bonus: re