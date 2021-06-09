/*
** EPITECH PROJECT, 2021
** MATRIX_MIX_COLUMNS
** File description:
** Matrix_mix_columns function
*/

#include "aes_matrix.h"

inline uint8_t xtime(uint8_t x)
{
    return (x << 1) ^ (((x >> 7) & 1) * 0x1b);
}

void matrix_mix_columns(aes_matrix_t block)
{
    uint8_t t;
    uint8_t u;

    for (int x = 0; x < 4; x++) {
        t = block[x][0] ^ block[x][1] ^ block[x][2] ^ block[x][3];
        u = block[x][0];
        block[x][0] ^= t ^ xtime(block[x][0] ^ block[x][1]);
        block[x][1] ^= t ^ xtime(block[x][1] ^ block[x][2]);
        block[x][2] ^= t ^ xtime(block[x][2] ^ block[x][3]);
        block[x][3] ^= t ^ xtime(block[x][3] ^ u);
    }
}

void matrix_inv_mix_columns(aes_matrix_t block)
{
    uint8_t u;
    uint8_t v;

    for (int x = 0; x < 4; x++) {
        u = xtime(xtime(block[x][0] ^ block[x][2]));
        v = xtime(xtime(block[x][1] ^ block[x][3]));
        block[x][0] ^= u;
        block[x][1] ^= v;
        block[x][2] ^= u;
        block[x][3] ^= v;
    }
    matrix_mix_columns(block);
}