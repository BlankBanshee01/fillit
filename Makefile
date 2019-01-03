# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/16 21:56:44 by iet-tibi          #+#    #+#              #
#    Updated: 2018/12/29 02:29:27 by iet-tibi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c validity.c board.c solving.c coordinates.c managers.c proper_coord.c libft/libft.a

all:
	make fclean -C libft
	make -C libft
	make clean -C libft
	gcc -Wall -Wextra -Werror -o fillit $(SRC)

clean:
	rm -Rf fillit