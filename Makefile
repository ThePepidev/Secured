##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Main Makefile for my_radar
##

MAIN = main.c

OBJ = $(MAIN:.c=.o)

NAME = libhashtable.a

LIBMY = libmy.a

HASHTABLE = hashtable.a

INCLUDE = -Iinclude -Ilib/my

CFLAGS += -Wall -Wextra $(INCLUDE)

all: $(NAME)

$(NAME):
	make -C lib/my
	make -C src/
	ar rcT $(NAME) $(LIBMY) $(HASHTABLE)

debug:	CFLAGS += -g
debug:	$(OBJ)
	make -C lib/my
	make -C src/
	$(NAME)

clean:
	rm -f $(OBJ)
	make -C lib/my clean
	make -C src/ clean

fclean: clean
	rm -f $(NAME)
	make -C lib/my fclean
	make -C src/ fclean

re: fclean all
