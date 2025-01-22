/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    if (!args)
        raise("Called Vertex constructor with missing arguments");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static int my_intlen(int nbr)
{
    if (nbr < 0)
        return 1 + my_intlen(-nbr);
    if (nbr < 10)
        return 1;
    return 1 + my_intlen(nbr / 10); 
}

static char *Vertex_str(VertexClass *this)
{
    int length = my_intlen(this->x) + my_intlen(this->y) +
        my_intlen(this->z) + 15 + 1;
    char *str = malloc(length);

    if (snprintf(str, length, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z) == -1)
        return NULL;
    return str;
}

static Object *Vertex_add(VertexClass *this, VertexClass *vertex)
{
    if (!this || !vertex)
        raise("Called Vertex add with missing arguments");
    return new(
        Vertex,
        this->x + vertex->x,
        this->y + vertex->y,
        this->z + vertex->z
    );
}

static Object *Vertex_sub(VertexClass *this, VertexClass *vertex)
{
    if (!this || !vertex)
        raise("Called Vertex sub with missing arguments");
    return new(
        Vertex,
        this->x - vertex->x,
        this->y - vertex->y,
        this->z - vertex->z
    );
}

// Create additional functions here

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = NULL,   /* Not needed atm */
        .__str__ = (to_string_t)&Vertex_str,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class *Vertex = (const Class *)&_description;
