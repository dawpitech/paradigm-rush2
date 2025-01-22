/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 05
*/

#include "float.h"
#include <stdio.h>

#include "array.h"
#include "int.h"
#include "new.h"

int main(void)
{
    Object *array = new(Array, 0, Int, 18);
    Object *it = begin(array);
    Object *it_end = end(array);
    Object *fl = new(Float, -0.752068);

    printf("%s\n", str(fl));
    printf("array size: %zu\n", len(array));
    // setitem(array, 5, 12);
    // setitem(array, 6, 13);
    while (lt(it, it_end)) {
        printf("%s\n", str(getval(it)));
        incr(it);
    }
    delete(it);
    delete(it_end);
    delete(array);
    return (0);
}
