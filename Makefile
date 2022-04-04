##
## EPITECH PROJECT, 2022
## GameEngine
## File description:
## Makefile
##

CC = gcc

SRC = $(shell find src -name "*.c") main.c
OBJ = $(SRC:.c=.o)

IFLAGS = -I ./include

CSFMLFLAGS = -lcsfml-audio
CSFMLFLAGS += -lcsfml-network
CSFMLFLAGS += -lcsfml-window
CSFMLFLAGS += -lcsfml-graphics
CSFMLFLAGS += -lcsfml-system

LFLAGS = $(CSFMLFLAGS) -lm -L ./lib/ -lmy

WFLAGS = -W -Wall -Werror -Wextra

CFLAGS = $(IFLAGS) $(LFLAGS) $(WFLAGS) -ggdb

NAME = alchemist

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/ all
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	find -name "*.o" -delete

fclean: clean
	make -C lib/ fclean
	rm -f $(NAME)

re: fclean all
