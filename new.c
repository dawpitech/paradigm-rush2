/*
** EPITECH PROJECT, 2025
** paradigm-rush2
** File description:
** new.c
*/

#include "object.h"

Object *new(const Class *class, ...)
{
    Object *obj;
    va_list val;

    if (class == NULL)
        raise("Called new on a NULL class");
    obj = calloc(1, class->__size__);
    memcpy(obj, class, class->__size__);
    va_start(val, class);
    if (class->__ctor__ != NULL)
        class->__ctor__(obj, &val);
    va_end(val);
    return obj;
}

Object *va_new(const Class *class, va_list *ap)
{
    Object *obj;

    if (class == NULL)
        raise("Called va_new on a NULL class");
    obj = calloc(1, class->__size__);
    memcpy(obj, class, class->__size__);
    if (class->__ctor__ != NULL)
        class->__ctor__(obj, ap);
    return obj;
}

void delete(Object *ptr)
{
    if (ptr == NULL)
        raise("Called destroy on a NULL object");
    if (((Class *)ptr)->__dtor__ != NULL)
        ((Class *)ptr)->__dtor__(ptr);
    free(ptr);
}
