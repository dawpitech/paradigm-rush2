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

T_CFLAGS	:=	$(CFLAGS)
T_CFLAGS	+=	-g3
T_CFLAGS	+=	-O0
T_CFLAGS	+=	-lcriterion
T_CFLAGS	+=	--coverage

BDIR	=	.build/release
T_BDIR	=	.build/test

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

T_SRC	:=	$(SRC)
T_SRC	+=	tests/ex01.c
T_SRC	+=	tests/ex02.c
T_SRC	+=	tests/ex03.c
T_SRC	+=	tests/ex04.c

OBJ = $(SRC:%.c=$(BDIR)/%.o)

OBJ_1 = $(SRC_1:%.c=$(BDIR)/%.o)
OBJ_2 = $(SRC_2:%.c=$(BDIR)/%.o)
OBJ_3 = $(SRC_3:%.c=$(BDIR)/%.o)
OBJ_4 = $(SRC_4:%.c=$(BDIR)/%.o)
OBJ_5 = $(SRC_5:%.c=$(BDIR)/%.o)

T_OBJ	=	$(T_SRC:%.c=$(T_BDIR)/%.o)

NAME = sources
T_NAME	=	unit_tests

GCOVR_OUTPUT = gcovr

.PHONY: all
all: ex01 ex02 ex03 ex04 ex05

$(BDIR)/%.o: %.c
	@ mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(CFLAGS)

$(T_BDIR)/%.o: %.c
	@ mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(T_CFLAGS)

$(T_NAME): $(T_OBJ)
	$(CC) $(T_OBJ) $(T_CFLAGS) -o $(T_NAME)

.PHONY: tests_run
tests_run: $(T_NAME)
	@-./$(T_NAME)

.PHONY: tests_run_pp
tests_run_pp:	$(T_NAME)
	@ -./$(T_NAME) --verbose --full-stats --color=always -j8
	@ mkdir -p $(GCOVR_OUTPUT)
	@ gcovr --exclude=tests --html-details $(GCOVR_OUTPUT)/output.html
	@ gcovr --exclude=tests
	@ gcovr --exclude=tests --txt-metric branch

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
	@ rm -rf $(T_BDIR)
	@ rm -d .build
	@ rm -rf $(GCOVR_OUTPUT)

.PHONY: fclean
fclean: clean
	@ rm -f ex01 ex02 ex03 ex04 ex05 $(T_NAME)

.NOTPARRALEL: re
.PHONY: re
re: fclean all
