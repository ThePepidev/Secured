##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Main Makefile for my_radar
##

SRC = 		src/insert.c			\
			src/hash.c				\
			src/search.c            \
			src/dump.c				\
			src/new_hashtable.c     \
			src/delete.c			\
			src/delete_hashtable.c  \

OBJ = $(SRC:.c=.o)

NAME = libhashtable.a

LIB = -L./lib -lmy

INCLUDE = -Iinclude -Ilib/my

CFLAGS += -Wall -Wextra $(INCLUDE)

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/my
	ar rc $(NAME) $(OBJ)

debug:	CFLAGS += -g
debug:	$(OBJ)
	make -C lib/my
	$(NAME)

clean:
	rm -f $(OBJ)
	make -C lib/my clean

fclean: clean
	rm -f $(NAME)
	make -C lib/my fclean

re: fclean all
