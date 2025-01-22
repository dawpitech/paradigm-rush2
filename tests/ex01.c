/*
** EPITECH PROJECT, 2025
** paradigm-rush2
** File description:
** ex1.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "player.h"
#include "new.h"

Test(ex01, basic_create_delete, .init = cr_redirect_stdout)
{
    Object *player = new(Player);
    delete(player);

    fflush(stdout);
    cr_assert_stdout_eq_str("Player()\n~Player()\n");
}
