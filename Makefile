NAME	= Cub3D
CC		= gcc
Make	= make
OS		= $(shell uname)
CFLAGS	= -Wall -Wextra -Werror
MLX_DIR	= minilibx-linux
MLX_LNK	= -L ${MLX_DIR} -lmlx -lXext -lX11 -lbsd
LIBS	= -L ft_printf ${MLX_LNK} -lm
INC		= -I $(MLX_DIR) -I libft -I getline -I ft_printf
OBJS	= ${SRCS:.c=.o}
SRCS	= cub3d.c libft/ft*.c getline/get*.c ft_printf/ft*.c ft_printf/pf*.c

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${INC}

all: ${NAME}

${NAME}: ${OBJS} build
		@echo "\033[35m-= Making Cub3D... =-"
		${CC} ${CFLAGS} ${INC} ${OBJS} ${LIBS} -o ${NAME}
		@echo "\033[32m   ______      __   _____ ____  "
		@echo "\033[32m  / ____/_  __/ /_ |__  // __ \ "
		@echo "\033[32m / /   / / / / __ \ /_ </ / / / "
		@echo "\033[32m/ /___/ /_/ / /_/ /__/ / /_/ /  "
		@echo "\033[32m\____/\__,_/_.___/____/_____/   usage: ./Cub3D <map.cub> [--save]"

build:
	@echo "\033[34m-= Making mlx, libft, and ft_printf... =-"
	@make -C $(MLX_DIR)
	@make -C ft_printf
	@echo "\033[34m-= mlx, libft, and ft_printf. Done ! =-"

bonus:
	re

clean:
	rm -f ${OBJS}

fclean: clean
	@echo "\033[33m-= Cleaning Libft... =-"
	@make fclean -C libft
	@echo "\033[34m-= Cleaning mlx... =-"
	@make clean -C $(MLX_DIR)
	@echo "\033[35m-= Cleaning Cub3D... =-"
	rm -f ${NAME}
	@echo "Done.\033[0;0m"

re: fclean all

.PHONY: all clean fclean re bonus mlx ft