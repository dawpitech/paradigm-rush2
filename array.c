/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 05
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "raise.h"
#include "array.h"
#include "new.h"

typedef struct
{
    Container   base;
    Class       *_type;
    size_t      _size;
    Object      **_tab;
}   ArrayClass;

typedef struct {
    Iterator    base;
    ArrayClass  *_array;
    size_t      _idx;
}   ArrayIteratorClass;

static void     ArrayIterator_ctor(ArrayIteratorClass *this, va_list *args)
{
    this->_array = va_arg(*args, ArrayClass *);
    this->_idx = va_arg(*args, int);
}

static bool     ArrayIterator_eq(ArrayIteratorClass *this, ArrayIteratorClass *other)
{
    return (this->_idx == other->_idx);
}

static bool     ArrayIterator_gt(ArrayIteratorClass *this, ArrayIteratorClass *other)
{
    return (this->_idx > other->_idx);
}

static bool     ArrayIterator_lt(ArrayIteratorClass *this, ArrayIteratorClass *other)
{
    return (this->_idx < other->_idx);
}

static void     ArrayIterator_incr(ArrayIteratorClass *this)
{
    this->_idx += 1;
}

static Object   *ArrayIterator_getval(ArrayIteratorClass *this)
{
    if (this->_idx >= this->_array->_size)
        raise("Out of range");
    return (this->_array->_tab[this->_idx]);
}

static void     ArrayIterator_setval(ArrayIteratorClass *this, ...)
{
    va_list val;
    int idx = 0;

    if (!this)
        raise("Error");
    va_start(val, this);
    idx = va_arg(val, int);
    delete(this->_array->_tab[idx]);
    this->_array->_tab[idx] = va_new(this->_array->_type, &val);
    va_end(val);
}

static const ArrayIteratorClass   ArrayIteratorDescr = {
    {   /* Iterator struct */
        {   /* Class struct */
            .__size__ = sizeof(ArrayIteratorClass),
            .__name__ = "ArrayIterator",
            .__ctor__ = (ctor_t)&ArrayIterator_ctor,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&ArrayIterator_eq,
            .__gt__ = (binary_comparator_t)&ArrayIterator_gt,
            .__lt__ = (binary_comparator_t)&ArrayIterator_lt,
        },
        .__incr__ = (incr_t)&ArrayIterator_incr,
        .__getval__ = (getval_t)&ArrayIterator_getval,
        .__setval__ = (setval_t)&ArrayIterator_setval,
    },
    ._array = NULL,
    ._idx = 0
};

static const Class    *ArrayIterator = (const Class *)&ArrayIteratorDescr;

static void     Array_ctor(ArrayClass *this, va_list *args)
{
    va_list val;
    
    if (!this || !args)
        raise("Error");
    this->_size = va_arg(*args, int);
    this->_type = va_arg(*args, Class *);
    this->_tab = calloc(this->_size, sizeof(this->_type));
    for (unsigned int i = 0; i < this->_size; i++) {
        va_copy(val, *args);
        this->_tab[i] = va_new(this->_type, &val);
    }
}

static void     Array_dtor(ArrayClass *this)
{
    for (unsigned int i = 0; i < this->_size; i++)
        delete(this->_tab[i]);
    free(this->_tab);
}

static size_t   Array_len(ArrayClass *this)
{
    return (this->_size);
}

static Iterator *Array_begin(ArrayClass *this)
{
    return (new(ArrayIterator, this, 0));
}

static Iterator *Array_end(ArrayClass *this)
{
    return (new(ArrayIterator, this, this->_size));
}

static Object   *Array_getitem(ArrayClass *this, ...)
{
    va_list val;
    Object *obj;

    if (!this)
        raise("Get item on empty array");
    va_start(val, this);
    obj = calloc(1, sizeof(this->_type));
    obj = va_new(this->_type, this->_tab[va_arg(val, int)]);
    va_end(val);
    return obj;
}

static void     Array_setitem(ArrayClass *this, ...)
{
    va_list val;
    size_t idx = 0;

    if (!this)
        raise("Set item on empty array");
    va_start(val, this);
    idx = va_arg(val, int);
    if (idx > this->_size)
        raise("Index out of range");
    delete(this->_tab[idx]);
    this->_tab[idx] = va_new(this->_type, &val);
    va_end(val);
}

static const ArrayClass   _descr = {
    {   /* Container struct */
        {   /* Class struct */
            .__size__ = sizeof(ArrayClass),
            .__name__ = "Array",
            .__ctor__ = (ctor_t)&Array_ctor,
            .__dtor__ = (dtor_t)&Array_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t)&Array_len,
        .__begin__ = (iter_t)&Array_begin,
        .__end__ = (iter_t)&Array_end,
        .__getitem__ = (getitem_t)&Array_getitem,
        .__setitem__ = (setitem_t)&Array_setitem,
    },
    ._type = NULL,
    ._size = 0,
    ._tab = NULL
};

const Class   *Array = (const Class *)&_descr;
