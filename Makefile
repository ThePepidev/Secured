##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Main Makefile for my_radar
##

SRC = 		src/secured.c

OBJ = $(SRC:.c=.o)

NAME = secured

LIB = -L./lib/my -lmy

INCLUDE = -Iinclude -Ilib/my

CFLAGS += -Wall -Wextra $(INCLUDE)

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(LIB) $(COMPILSFML) $(CFLAGS)

debug: $(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)

clean:
	rm -f $(OBJ)
	make -C lib/my clean

fclean: clean
	rm -f $(NAME)
	make -C lib/my fclean

re: fclean all
