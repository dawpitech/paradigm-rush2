/*
** EPITECH PROJECT, 2025
** paradigm-rush2
** File description:
** ex2.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "vertex.h"
#include "point.h"
#include "new.h"
#include "test_utils.h"

Test(ex02, basic_create_delete)
{
    Object *point = new(Point, 42, -42);
    Object *vertex = new(Vertex, 0, 1, 2);

    delete(point);
    delete(vertex);
    cr_pass();
}

Test(ex02, check_str_output, .init = cr_redirect_stdout)
{
    Object *point = new(Point, 42, -42);
    Object *vertex = new(Vertex, 0, 1, 2);

    printf("point = %s\n", str(point));
    printf("vertex = %s\n", str(vertex));

    delete(point);
    delete(vertex);
    fflush(stdout);
    cr_assert_stdout_eq_str("point = <Point (42, -42)>\nvertex = <Vertex (0, 1, 2)>\n");
}
