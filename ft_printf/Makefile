# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mg <mg@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/09 17:00:23 by mg                #+#    #+#              #
#    Updated: 2020/06/17 16:15:32 by mg               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the library
NAME=libftprintf.a

SRCS=./libft/ft*.c ft*.c pf*.c

OBJECTS=ft*.o pf*.o

INCLUDES=./

all:$(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

bonus: re

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
