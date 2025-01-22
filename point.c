/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    if (!args)
        raise("Called Point constructor with missing arguments");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
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

static char *Point_str(PointClass *this)
{
    int length = my_intlen(this->x) + my_intlen(this->y) + 12 + 1;
    char *str = malloc(length);

    if (snprintf(str, length, "<Point (%d, %d)>", this->x, this->y) == -1)
        return NULL;
    return str;
}

static Object *Point_add(const PointClass *a, const PointClass *b)
{
    if (!a || !b)
        raise("Called Point add with missing arguments");

    return new(Point, a->x + b->x, a->y + b->y);
}

static Object *Point_sub(const PointClass *a, const PointClass *b)
{
    if (!a || !b)
        raise("Called Point sub with missing arguments");

    return new(Point, a->x - b->x, a->y - b->y);
}

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = NULL,   /* Not needed atm */
        .__str__ = (to_string_t)&Point_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Point_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Point_sub,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
