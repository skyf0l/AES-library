/*
** EPITECH PROJECT, 2021
** TESTS_AES
** File description:
** Tests_aes header
*/

#ifndef TESTS_AES_H_
#define TESTS_AES_H_

#include "aes.h"

#define CHECK_BLOCK_EQUALITY(b1, b2)                                           \
    cr_assert_eq(memcmp(b1, b2, AES_BLOCK_SIZE), 0);

#define CHECK_BLOCKS_EQUALITY(bs1, bs2, nb_blocks)                             \
    for (size_t k = 0; k < nb_blocks; k++)                                     \
        CHECK_BLOCK_EQUALITY(bs1[k], bs2[k]);

#define CHECK_MATRIX_EQUALITY(m1, m2)                                          \
    for (size_t y = 0; y < 4; y++)                                             \
        for (size_t x = 0; x < 4; x++)                                         \
            cr_assert_eq(m1[y][x], m2[y][x]);

#endif /* !TESTS_AES_H_ */