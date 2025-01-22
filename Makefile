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
SRC	+=	src/point.c
SRC	+=	new.c

OBJ = $(SRC:%.c=$(BDIR)/%.o)

NAME = rush2

.PHONY: all
all: ex01

$(BDIR)/%.o: %.c
	@ mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(CFLAGS) -Wno-unused-parameter

$(NAME): $(OBJ)
	@ ar rc ${NAME} $(OBJ)

ex01: $(OBJ)
	@ $(CC) $(OBJ) mains/ex01.c $(CFLAGS) -o $(NAME)

.PHONY: clean
clean:
	@ rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	@ rm -f $(NAME)

.NOTPARRALEL: re
.PHONY: re
re: fclean all
