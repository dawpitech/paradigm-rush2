/*
** EPITECH PROJECT, 2025
** paradigm-rush2
** File description:
** ex03.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "vertex.h"
#include "point.h"
#include "new.h"
#include "test_utils.h"

Test(ex03, basic_create_delete)
{
    Object *p1 = new(Point, 12, 13);
    Object *p2 = new(Point, 2, 2);

    Object *v1 = new(Vertex, 1, 2, 3);
    Object *v2 = new(Vertex, 4, 5, 6);

    delete(v1);
    delete(v2);
    delete(p1);
    delete(p2);
    cr_pass();
}

Test(ex03, check_add_and_sub, .init = cr_redirect_stdout)
{
    Object *p1 = new(Point, 12, 13);
    Object *p2 = new(Point, 2, 2);

    printf("%s + %s = %s\n", str(p1), str(p2), str(addition(p1, p2)));
    printf("%s - %s = %s\n", str(p1), str(p2), str(subtraction(p1, p2)));

    Object *v1 = new(Vertex, 1, 2, 3);
    Object *v2 = new(Vertex, 4, 5, 6);

    printf("%s + %s = %s\n", str(v1), str(v2), str(addition(v1, v2)));
    printf("%s - %s = %s\n", str(v1), str(v2), str(subtraction(v1, v2)));

    delete(v1);
    delete(v2);
    delete(p1);
    delete(p2);
    fflush(stdout);
    cr_assert_stdout_eq_str(""
        "<Point (12, 13)> + <Point (2, 2)> = <Point (14, 15)>\n"
        "<Point (12, 13)> - <Point (2, 2)> = <Point (10, 11)>\n"
        "<Vertex (1, 2, 3)> + <Vertex (4, 5, 6)> = <Vertex (5, 7, 9)>\n"
        "<Vertex (1, 2, 3)> - <Vertex (4, 5, 6)> = <Vertex (-3, -3, -3)>\n"
    );
}
