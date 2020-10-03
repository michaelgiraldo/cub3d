# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgiraldo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 14:40:16 by mgiraldo          #+#    #+#              #
#    Updated: 2020/03/05 16:31:02 by mgiraldo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the library
NAME=libft.a

SRCS=ft*.c

OBJECTS=ft*.o

INCLUDES=./

all:$(NAME)

$(NAME):$(SRCS)	libft.h
	@gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

bonus: re

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
