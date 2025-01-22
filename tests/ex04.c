/*
** EPITECH PROJECT, 2025
** paradigm-rush2
** File description:
** ex04.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

#include "char.h"
#include "int.h"
#include "float.h"
#include "new.h"
#include "test_utils.h"

static void compareAndDivide(Object *a, Object *b)
{
    if (gt(a, b))
        printf("a > b\n");
    else if (lt(a, b))
        printf("a < b\n");
    else
        printf("a == b\n");
    printf("a / b = %s\n", str(division(a, b)));
}

Test(ex04, str_output_with_compares, .init = cr_redirect_stdout)
{
    Object *c1 = new(Char, 98);
    Object *c2 = new(Char, 2);

    compareAndDivide(c1, c2);

    Object *i1 = new(Int, 9);
    Object *i2 = new(Int, 3);

    compareAndDivide(i1, i2);

    Object *f1 = new(Float, 7.5);
    Object *f2 = new(Float, 3.0);

    compareAndDivide(f1, f2);
    delete(c1);
    delete(c2);
    delete(i1);
    delete(i2);
    delete(f1);
    delete(f2);
    fflush(stdout);
    cr_assert_stdout_eq_str(""
        "a > b\n"
        "a / b = <Char (1)>\n"
        "a > b\n"
        "a / b = <Int (3)>\n"
        "a > b\n"
        "a / b = <Float (2.500000)>\n"
    );
}

Test(ex04, greater_than_int)
{
    Object *i1 = new(Int, 2);
    Object *i2 = new(Int, 5);

    cr_expect(gt(i2, i1));
    cr_assert(!(gt(i1, i2)));
}

Test(ex04, less_than_int)
{
    Object *i1 = new(Int, 2);
    Object *i2 = new(Int, 5);

    cr_expect(!(lt(i2, i1)));
    cr_assert(gt(i2, i1));
}

Test(ex04, equal_int)
{
    Object *i1 = new(Int, 2);
    Object *i2 = new(Int, 5);
    Object *i3 = new(Int, 5);

    cr_expect(!(eq(i1, i2)));
    cr_assert(eq(i2, i3));
}

Test(ex04, mul_int)
{
    Object *i1 = new(Int, 2);
    Object *i2 = new(Int, 5);
    Object *i3 = new(Int, 10);

    cr_assert(eq(multiplication(i1, i2), i3));
}

Test(ex04, sub_int)
{
    Object *i1 = new(Int, 5);
    Object *i2 = new(Int, 2);
    Object *i3 = new(Int, 3);

    cr_assert(eq(subtraction(i1, i2), i3));
}
