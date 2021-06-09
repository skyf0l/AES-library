/*
** EPITECH PROJECT, 2021
** AES_TOOLS
** File description:
** Aes_tools function
*/

#include "aes_tools.h"

void block_to_matrix(aes_matrix_t matrix, const aes_block_t block)
{
    for (int y = 0; y < 4; y++)
        for (int x = 0; x < 4; x++)
            matrix[y][x] = block[y * 4 + x];
}

void matrix_to_block(aes_block_t block, const aes_matrix_t matrix)
{
    for (int y = 0; y < 4; y++)
        for (int x = 0; x < 4; x++)
            block[y * 4 + x] = matrix[y][x];
}

void aes_xor_block(aes_block_t to_xor, const aes_block_t xor_by)
{
    for (size_t k = 0; k < AES_BLOCK_SIZE; k++)
        to_xor[k] ^= xor_by[k];
}