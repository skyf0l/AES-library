/*
** EPITECH PROJECT, 2021
** MATRIX_ADD_ROUND_KEY
** File description:
** Matrix_add_round_key function
*/

#include "aes_matrix.h"

void matrix_add_round_key(aes_matrix_t block, aes_matrix_t round_key)
{
    for (int y = 0; y < 4; y++)
        for (int x = 0; x < 4; x++)
            block[y][x] ^= round_key[y][x];
}