/*
** EPITECH PROJECT, 2025
** paradigm-rush2
** File description:
** ex05.c
*/

#include <criterion/criterion.h>
#include <stdio.h>

#include "float.h"
#include "array.h"
#include "int.h"
#include "new.h"
#include "test_utils.h"

Test(ex05, basic)
{

    Object *array = new(Array, 0, Int, 18);
    Object *it = begin(array);
    Object *it_end = end(array);
    Object *fl = new(Float, -0.752068);

    while (lt(it, it_end)) {
        incr(it);
    }
    delete(it);
    delete(it_end);
    delete(array);
    cr_pass();
};
