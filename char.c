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
    Class   base;
    int c;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    if (!args)
        raise("Called Char constructor with missing arguments");
    this->c = va_arg(*args, int);
}

static char *Char_str(CharClass *this)
{
    int length = sizeof(char) + 9 + 1;
    char *str = malloc(length);

    if (snprintf(str, length, "<Char (%c)>", this->c) == -1)
        return NULL;
    return str;
}

static Object *Char_add(CharClass *this, CharClass *c)
{
    if (!this || !c)
        raise("Invalid argument");
    return new(
        Char,
        this->c + c
    );
}

static Object *Char_sub(CharClass *this, CharClass *c)
{
    if (!this || !c)
        raise("Invalid argument");
    return new(
        Char,
        this->c - c->c
    );
}

static Object *Char_mul(CharClass *this, CharClass *c)
{
    if (!this || !c)
        raise("Invalid argument");
    return new(
        Char,
        this->c * c->c
    );
}

static Object *Char_div(CharClass *this, CharClass *c)
{
    if (!this || !c)
        raise("Invalid argument");
    if (c->c == 0)
        raise("Cannot divide by 0!");
    return new(
        Char,
        this->c / c->c
    );
}

static bool Char_eq(CharClass *this, CharClass *c)
{
    if (!this || !c)
        raise("Invalid argument");
    return this->c == c->c;
}

static bool Char_gt(CharClass *this, CharClass *c)
{
    if (!this || !c)
        raise("Invalid argument");
    return this->c > c->c;
}

static bool Char_lt(CharClass *this, CharClass *c)
{
    if (!this || !c)
        raise("Invalid argument");
    return this->c < c->c;
}

// Create additional functions here

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = NULL,   /* Not needed atm */
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .c = '\0',
};

const Class *Char = (const Class *)&_description;
