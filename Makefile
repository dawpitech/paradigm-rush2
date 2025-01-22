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

BDIR	=	.build

SRC	=	array.c
SRC	+=	src/player.c
SRC	+=	point.c
SRC	+=	vertex.c
SRC	+=	char.c
SRC	+=	new.c
SRC +=  int.c
SRC	+=	float.c

SRC_1 = mains/ex01.c
SRC_2 = mains/ex02.c
SRC_3 = mains/ex03.c
SRC_4 = mains/ex04.c
SRC_5 = mains/ex05.c

OBJ = $(SRC:%.c=$(BDIR)/%.o)

OBJ_1 = $(SRC_1:%.c=$(BDIR)/%.o)
OBJ_2 = $(SRC_2:%.c=$(BDIR)/%.o)
OBJ_3 = $(SRC_3:%.c=$(BDIR)/%.o)
OBJ_4 = $(SRC_4:%.c=$(BDIR)/%.o)
OBJ_5 = $(SRC_5:%.c=$(BDIR)/%.o)

NAME = sources

.PHONY: all
all: ex01 ex02 ex03 ex04 ex05

$(BDIR)/%.o: %.c
	@ mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(CFLAGS) -Wno-unused-parameter

ex01: $(OBJ) $(OBJ_1)
	@ $(CC) $(OBJ) $(OBJ_1) $(CFLAGS) -o ex01

ex02: $(OBJ) $(OBJ_2)
	@ $(CC) $(OBJ) $(OBJ_2) $(CFLAGS) -o ex02

ex03: $(OBJ) $(OBJ_3)
	@ $(CC) $(OBJ) $(OBJ_3) $(CFLAGS) -o ex03

ex04: $(OBJ) $(OBJ_4)
	@ $(CC) $(OBJ) $(OBJ_4) $(CFLAGS) -o ex04

ex05: $(OBJ) $(OBJ_5)
	@ $(CC) $(OBJ) $(OBJ_5) $(CFLAGS) -o ex05

.PHONY: clean
clean:
	@ rm -f $(OBJ)
	@ rm -rf $(BDIR)

.PHONY: fclean
fclean: clean
	@ rm -f ex01 ex02 ex03 ex04 ex05

.NOTPARRALEL: re
.PHONY: re
re: fclean all
