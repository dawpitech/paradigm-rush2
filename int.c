/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include <stdlib.h>

#include "int.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    if (!args)
        raise("Called Point constructor with missing arguments");
    this->x = va_arg(*args, int);
}

// Create additional functions here

static int my_intlen(int nbr)
{
    if (nbr < 0)
        return 1 + my_intlen(-nbr);
    if (nbr < 10)
        return 1;
    return 1 + my_intlen(nbr / 10); 
}

static char *Int_str(IntClass *this)
{
    int length = my_intlen(this->x)+ 1;
    char *str = malloc(length);

    if (snprintf(str, length, "<Int (%d)>", this->x) == -1)
        return NULL;
    return str;
}

static Object *Int_add(const IntClass *a, const IntClass *b)
{
    if (!a || !b)
        raise("Error");

    return new(Int, a->x + b->x);
}

static Object *Int_sub(const IntClass *a, const IntClass *b)
{
    if (!a || !b)
        raise("Error");

    return new(Int, a->x - b->x);
}

static Object *Int_mul(const IntClass *a, const IntClass *b)
{
    if (!a || !b)
        raise("Error");

    return new(Int, a->x * b->x);
}

static Object *Int_div(const IntClass *a, const IntClass *b)
{
    if (!a || !b)
        raise("Error");
    if (b->x == 0)
        raise("Divided by 0");

    return new(Int, a->x / b->x);
}

static bool Int_eq(const IntClass *a, const IntClass *b)
{
    if (!a || !b)
        raise("Error");
    if (a != b)
        return false;
    return true;
}

static bool Int_gt(const IntClass *a, const IntClass *b)
{
    if (!a || !b)
        raise("Error");
    if (a <= b)
        return false;
    return true;
}

static bool Int_lt(const IntClass *a, const IntClass *b)
{
    if (!a || !b)
        raise("Error");
    if (a >= b)
        return false;
    return true;
}

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = NULL,   /* Not needed atm */
        .__str__ = (to_string_t)&Int_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Int_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Int_sub,    /* Implement this method for exercice 03 */
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .x = 0,
};

const Class   *Int = (const Class *)&_description;
