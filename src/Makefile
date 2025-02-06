##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Main Makefile for my_radar
##

SRC = 	insert.c			\
		hash.c				\
		search.c            \
		dump.c				\
		new_hashtable.c     \
		delete.c			\
		delete_hashtable.c

OBJ = $(SRC:.c=.o)

NAME = hashtable.a

INCLUDE = -I../include

CFLAGS += -Wall -Wextra $(INCLUDE)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ../lib/my
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../.

debug:	CFLAGS += -g
debug:	$(OBJ)
	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../hashtable.a

re: fclean all
