NAME = fillit

SRC = src/main.c src/validity.c src/board.c src/solving.c src/coordinates.c src/managers.c src/proper_coord.c libft/libft.a

all: $(NAME)

$(NAME):
	make -C libft
	gcc -Wall -Wextra -Werror -o fillit $(SRC)

clean:
	make clean -C libft

fclean:
	make fclean -C libft
	rm -rf fillit

re: fclean all