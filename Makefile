##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

CC	:=	gcc -std=gnu17

CFLAGS	=	-W
CFLAGS	+=	-Wall
CFLAGS	+=	-Wextra
CFLAGS	+=	-Wundef
CFLAGS	+=	-Wshadow
CFLAGS	+=	-Wunreachable-code
CLFAGS	+=	-Wmissing-prototypes
CFLAGS	+=	-pedantic
CFLAGS	+=	-iquote include

BDIR	=	.build/

SRC	=	src/array.c
SRC	+=	src/player.c
SRC	+=	point.c
SRC	+=	vertex.c
SRC	+=	new.c

OBJ = $(SRC:%.c=$(BDIR)/%.o)

NAME = sources

.PHONY: all
all: ex01 ex02

$(BDIR)/%.o: %.c
	@ mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(CFLAGS) -Wno-unused-parameter

ex01: $(OBJ)
	@ $(CC) $(OBJ) mains/ex01.c $(CFLAGS) -o ex01

ex02: $(OBJ)
	@ $(CC) $(OBJ) mains/ex02.c $(CFLAGS) -o ex02

.PHONY: clean
clean:
	@ rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	@ rm -f ex01 ex02 ex03 ex04 ex05

.NOTPARRALEL: re
.PHONY: re
re: fclean all
