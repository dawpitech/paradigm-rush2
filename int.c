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
    Class base;
    int value;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    if (this == NULL)
        raise("Invalid int object passed to constructor");
    if (args == NULL)
        raise("Called int constructor with missing arguments");
    this->value = va_arg(*args, int);
}

// Create additional functions here

static int my_intlen(const int nbr)
{
    if (nbr < 0)
        return 1 + my_intlen(-nbr);
    if (nbr < 10)
        return 1;
    return 1 + my_intlen(nbr / 10); 
}

static char *Int_str(IntClass *this)
{
    int length;
    char *str;

    if (this == NULL)
        raise("Invalid int object passed to str");
    length = my_intlen(this->value) + 10;
    str = calloc(1, length);
    if (snprintf(str, length, "<Int (%d)>", this->value) == -1)
        return NULL;
    return str;
}

static Object *Int_add(const IntClass *a, const IntClass *b)
{
    if (a == NULL || b == NULL)
        raise("Invalid int objects passed to add");
    return new(Int, a->value + b->value);
}

static Object *Int_sub(const IntClass *a, const IntClass *b)
{
    if (a == NULL || b == NULL)
        raise("Invalid int objects passed to sub");
    return new(Int, a->value - b->value);
}

static Object *Int_mul(const IntClass *a, const IntClass *b)
{
    if (a == NULL || b == NULL)
        raise("Invalid int objects passed to mul");
    return new(Int, a->value * b->value);
}

static Object *Int_div(const IntClass *a, const IntClass *b)
{
    if (a == NULL || b == NULL)
        raise("Invalid int objects passed to div");
    if (b->value == 0)
        raise("Trying to divide by an int zero");
    return new(Int, a->value / b->value);
}

static bool Int_eq(const IntClass *a, const IntClass *b)
{
    if (a == NULL || b == NULL)
        raise("Invalid int objects passed to eq");
    return a->value == b->value ? true : false;
}

static bool Int_gt(const IntClass *a, const IntClass *b)
{
    if (a == NULL || b == NULL)
        raise("Invalid int objects passed to qt");
    return a->value > b->value ? true : false;
}

static bool Int_lt(const IntClass *a, const IntClass *b)
{
    if (a == NULL || b == NULL)
        raise("Invalid int objects passed to lt");
    return a->value < b->value ? true : false;
}

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = NULL,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .value = -1,
};

const Class   *Int = (const Class *)&_description;
