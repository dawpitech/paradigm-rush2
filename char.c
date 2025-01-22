/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>

#include "char.h"
#include "new.h"

typedef struct
{
    Class base;
    char chr;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    if (this == NULL)
        raise("Invalid char object passed to constructor");
    if (args == NULL)
        raise("Called char constructor with missing arguments");
    this->chr = (char) va_arg(*args, int);
}

static char *Char_str(CharClass *this)
{
    int length = 11;
    char *str;

    if (this == NULL)
        raise("Invalid char object passed to str");
    str = calloc(1, length);
    if (snprintf(str, length, "<Char (%c)>", this->chr) == -1)
        return NULL;
    return str;
}

static Object *Char_add(const CharClass *a, const CharClass *b)
{
    if (a == NULL || b == NULL)
        raise("Invalid char objects passed to add");
    return new(Char, a->chr + b->chr);
}

static Object *Char_sub(const CharClass *a, const CharClass *b)
{
    if (a == NULL || b == NULL)
        raise("Invalid char objects passed to sub");
    return new(Char, a->chr - b->chr);
}

static Object *Char_mul(const CharClass *a, const CharClass *b)
{
    if (a == NULL || b == NULL)
        raise("Invalid char objects passed to mul");
    return new(Char, a->chr * b->chr);
}

static Object *Char_div(const CharClass *a, const CharClass *b)
{
    if (a == NULL || b == NULL)
        raise("Invalid char objects passed to div");
    if (b->chr == 0)
        raise("Trying to divide by a char zero");
    return new(Char, (char) (a->chr / b->chr));
}

static bool Char_eq(const CharClass *a, const CharClass *b)
{
    if (a == NULL || b == NULL)
        raise("Invalid char objects passed to eq");
    return a->chr == b->chr ? true : false;
}

static bool Char_gt(const CharClass *a, const CharClass *b)
{
    if (a == NULL || b == NULL)
        raise("Invalid char objects passed to qt");
    return a->chr > b->chr ? true : false;
}

static bool Char_lt(const CharClass *a, const CharClass *b)
{
    if (a == NULL || b == NULL)
        raise("Invalid char objects passed to lt");
    return a->chr < b->chr ? true : false;
}

// Create additional functions here

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = NULL,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .chr = '\0',
};

const Class *Char = (const Class *)&_description;
