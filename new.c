/*
** EPITECH PROJECT, 2025
** paradigm-rush2
** File description:
** new.c
*/

#include "object.h"

Object  *new(const Class *class, ...)
{
    Object *obj;

    if (class == NULL)
        raise("Called new a NULL class");
    obj = calloc(1, class->__size__);
    if (class->__ctor__ != NULL)
        class->__ctor__(obj, NULL);
    return obj;
}

void delete(Object *ptr)
{
    if (ptr == NULL)
        raise("Called destroy on a NULL object");
    Class *obj_class = ptr;
    if (obj_class->__dtor__ != NULL)
        obj_class->__dtor__(ptr);
    free(ptr);
}
