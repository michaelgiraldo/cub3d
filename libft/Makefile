# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mg <mg@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 14:40:16 by mgiraldo          #+#    #+#              #
#    Updated: 2020/10/05 18:26:48 by mg               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the library
NAME=libft.a

#Source
SRC=ft*.c

#Object
OBJ=ft*.o

#Include
INC=-I ./

FLAGS=-Wall -Wextra -Werror

all:$(NAME)

$(NAME):
	@gcc ${FLAGS} $(INC) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

bonus: re

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
