/*
** EPITECH PROJECT, 2021
** MATRIX_SHIFT_ROWS
** File description:
** Matrix_shift_rows function
*/

#include "aes_matrix.h"

void matrix_shift_rows(aes_matrix_t block)
{
    uint8_t tmp;

    tmp = block[0][1];
    block[0][1] = block[1][1];
    block[1][1] = block[2][1];
    block[2][1] = block[3][1];
    block[3][1] = tmp;
    tmp = block[0][2];
    block[0][2] = block[2][2];
    block[2][2] = tmp;
    tmp = block[1][2];
    block[1][2] = block[3][2];
    block[3][2] = tmp;
    tmp = block[0][3];
    block[0][3] = block[3][3];
    block[3][3] = block[2][3];
    block[2][3] = block[1][3];
    block[1][3] = tmp;
}

void matrix_inv_shift_rows(aes_matrix_t block)
{
    uint8_t tmp;

    tmp = block[3][1];
    block[3][1] = block[2][1];
    block[2][1] = block[1][1];
    block[1][1] = block[0][1];
    block[0][1] = tmp;
    tmp = block[0][2];
    block[0][2] = block[2][2];
    block[2][2] = tmp;
    tmp = block[1][2];
    block[1][2] = block[3][2];
    block[3][2] = tmp;
    tmp = block[0][3];
    block[0][3] = block[1][3];
    block[1][3] = block[2][3];
    block[2][3] = block[3][3];
    block[3][3] = tmp;
}