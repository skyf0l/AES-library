/*
** EPITECH PROJECT, 2021
** TESTS_AES_TOOLS
** File description:
** Test aes_tools
*/

#include <criterion/criterion.h>

#include "aes_tools.h"

Test(block_to_matrix, basic)
{
    const aes_block_t block = "0123456789abcdef";
    aes_matrix_t matrix;

    block_to_matrix(matrix, block);
    for (int y = 0; y < 4; y++)
        for (int x = 0; x < 4; x++)
            cr_assert_eq(matrix[y][x], block[y * 4 + x]);
}

Test(matrix_to_block, basic)
{
    const aes_matrix_t matrix = { "0123", "4567", "89ab", "cdef" };
    aes_block_t block;

    matrix_to_block(block, matrix);
    for (int y = 0; y < 4; y++)
        for (int x = 0; x < 4; x++)
            cr_assert_eq(block[y * 4 + x], matrix[y][x]);
}