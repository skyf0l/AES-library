/*
** EPITECH PROJECT, 2021
** AES_MATRIX
** File description:
** Aes_matrix header
*/

#ifndef AES_MATRIX_H_
#define AES_MATRIX_H_

#include "aes.h"

void matrix_add_round_key(aes_matrix_t block, aes_matrix_t round_key);

void matrix_sub_bytes(aes_matrix_t block);
void matrix_inv_sub_bytes(aes_matrix_t block);

void matrix_shift_rows(aes_matrix_t block);
void matrix_inv_shift_rows(aes_matrix_t block);

void matrix_mix_columns(aes_matrix_t block);
void matrix_inv_mix_columns(aes_matrix_t block);

#endif /* !AES_MATRIX_H_ */