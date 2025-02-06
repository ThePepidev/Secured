##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Main Makefile for my_radar
##

SRC = 		src/insert.c			\
			main.c

OBJ = $(SRC:.c=.o)

NAME = secured

LIB = -L./lib -lmy

INCLUDE = -Iinclude -Ilib/my

CFLAGS += -Wall -Wextra $(INCLUDE) -g

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)

debug:	CFLAGS += -g
debug:	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LIB)

clean:
	rm -f $(OBJ)
	make -C lib/my clean

fclean: clean
	rm -f $(NAME)
	make -C lib/my fclean

re: fclean all
