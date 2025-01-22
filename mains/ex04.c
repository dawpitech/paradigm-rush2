/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 04
*/

#include <stdio.h>
#include "new.h"
#include "char.h"
#include "int.h"
#include "float.h"

static void compareAndDivide(Object *a, Object *b)
{
    if (gt(a, b))
        printf("a > b\n");
    else if (lt(a, b))
        printf("a < b\n");
    else
        printf("a == b\n");
    printf("a / b = %s\n", str(division(a, b)));
}

int main(void)
{
    Object *c1 = new(Char, 98);
    Object *c2 = new(Char, 2);

    compareAndDivide(c1, c2);

    Object *i1 = new(Int, 9);
    Object *i2 = new(Int, 3);

    compareAndDivide(i1, i2);

    Object *f1 = new(Float, 7.5);
    Object *f2 = new(Float, 3.0);

    compareAndDivide(f1, f2);
    delete(c1);
    delete(c2);
    delete(i1);
    delete(i2);
    delete(f1);
    delete(f2);
    return (0);
}
