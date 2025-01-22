/*
** EPITECH PROJECT, 2025
** paradigm-rush2
** File description:
** float.c
*/

#include <stdio.h>
#include <stdlib.h>

#include "float.h"
#include "new.h"

typedef struct
{
    Class base;
    float value;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    if (this == NULL)
        raise("Invalid float object passed to constructor");
    if (args == NULL)
        raise("Called float constructor with missing arguments");
    this->value = va_arg(*args, float);
}

static int my_intlen(const int nbr)
{
    if (nbr < 0)
        return 1 + my_intlen(-nbr);
    if (nbr < 10)
        return 1;
    return 1 + my_intlen(nbr / 10);
}

static char *Float_str(FloatClass *this)
{
    int length;
    char *str;

    if (this == NULL)
        raise("Invalid float object passed to str");
    length = my_intlen((int)this->value) + 18;
    str = calloc(1, length);
    printf("L:%d\n", length);
    if (snprintf(str, length, "<Float (%f)>", this->value) == -1)
        return NULL;
    return str;
}

static Object *Float_add(const FloatClass *a, const FloatClass *b)
{
    if (a == NULL || b == NULL)
        raise("Invalid float objects passed to add");
    return new(Float, a->value + b->value);
}

static Object *Float_sub(const FloatClass *a, const FloatClass *b)
{
    if (a == NULL || b == NULL)
        raise("Invalid float objects passed to sub");
    return new(Float, a->value - b->value);
}

static Object *Float_mul(const FloatClass *a, const FloatClass *b)
{
    if (a == NULL || b == NULL)
        raise("Invalid float objects passed to mul");
    return new(Float, a->value * b->value);
}

static Object *Float_div(const FloatClass *a, const FloatClass *b)
{
    if (a == NULL || b == NULL)
        raise("Invalid float objects passed to div");
    if (b->value == 0)
        raise("Trying to divide by a float zero");
    return new(Float, a->value / b->value);
}

static bool Float_eq(const FloatClass *a, const FloatClass *b)
{
    if (a == NULL || b == NULL)
        raise("Invalid float objects passed to eq");
    return a == b ? true : false;
}

static bool Float_gt(const FloatClass *a, const FloatClass *b)
{
    if (a == NULL || b == NULL)
        raise("Invalid float objects passed to qt");
    return a > b ? true : false;
}

static bool Float_lt(const FloatClass *a, const FloatClass *b)
{
    if (a == NULL || b == NULL)
        raise("Invalid float objects passed to lt");
    return a < b ? true : false;
}

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = NULL,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .value = -1,
};

const Class *Float = (const Class *)&_description;
