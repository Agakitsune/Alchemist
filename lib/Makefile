##
## EPITECH PROJECT, 2022
## lib
## File description:
## Makefile
##

CC = gcc
ASM = nasm

SRC = $(shell find -name "*.c" | grep -v test | grep -v main)
ASM_SRC = $(shell find -name "*.asm" | grep -v test | grep -v main)

TEST = $(shell find -name "*.c" | grep test)

HEADER = $(shell find -name "*.h")

OBJ = $(SRC:.c=.o)
ASM_OBJ = $(ASM_SRC:.asm=.o)

IFLAGS = -I ../include

WFLAGS = -W -Wall -Wextra -Werror

ifeq (DEBUG, ALL)
	WFLAGS += -D_POSIX_C_SOURCE=200809L -D_GNU_SOURCE -std=c99
	WFLAGS += -Wno-error=init-self -Winit-self
	WFLAGS += -Wno-error=shadow -Wshadow
	WFLAGS += -Wno-error=pointer-arith -Wpointer-arith
	WFLAGS += -Wno-error=duplicated-cond -Wduplicated-cond
	WFLAGS += -Wno-error=switch-enum -Wswitch-enum
	WFLAGS += -Wno-error=declaration-after-statement -Wdeclaration-after-statement
	WFLAGS += -Wno-error=float-equal -Wfloat-equal
	WFLAGS += -Wno-error=tautological-compare -Wtautological-compare
	WFLAGS += -Wno-error=array-bounds -Warray-bounds
	WFLAGS += -Wno-error=alloc-zero -Walloc-zero
	WFLAGS += -Wno-error=cast-qual -Wcast-qual
	WFLAGS += -Wno-error=extra -Wextra -Wnonnull
	WFLAGS += -fno-builtin
endif

CFLAGS = $(IFLAGS) $(WFLAGS) -g3 -ggdb
ASMFLAGS = -f elf64

NAME = libmy.a

all: $(NAME)

build:
	cp $(HEADER) ../include
	mv $(TEST) ../tests

%.o: %.asm
	$(ASM) $(ASMFLAGS) $< -o $@

$(NAME): $(OBJ) $(ASM_OBJ)
	ar rc $(NAME) $(OBJ) $(ASM_OBJ)

clean:
	rm -f $(OBJ)
	rm -f $(ASM_OBJ)
	find -name "*.gc*" -delete

fclean: clean
	rm -f $(NAME)
	rm -f test

re: fclean all

tests_run: fclean
	$(CC) -o debug $(SRC) $(TEST) $(CFLAGS) --coverage -lcriterion
	./test