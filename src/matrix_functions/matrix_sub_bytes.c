/*
** EPITECH PROJECT, 2021
** MATRIX_SUB_BYTES
** File description:
** Matrix_sub_bytes function
*/

#include "aes_boxes.h"

#include "aes_matrix.h"

void matrix_sub_bytes(aes_matrix_t block)
{
    for (int y = 0; y < 4; y++)
        for (int x = 0; x < 4; x++)
            block[y][x] = AES_SBOX[block[y][x]];
}

void matrix_inv_sub_bytes(aes_matrix_t block)
{
    for (int y = 0; y < 4; y++)
        for (int x = 0; x < 4; x++)
            block[y][x] = AES_INV_SBOX[block[y][x]];
}