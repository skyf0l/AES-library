/*
** EPITECH PROJECT, 2021
** AES_TOOLS
** File description:
** Aes_tools header
*/

#ifndef AES_TOOLS_H_
#define AES_TOOLS_H_

#include "aes.h"

// random
int aes_gen_n_random_bytes(uint8_t *buff, size_t buff_len);

// encrypt / decript
void aes_encrypt_block(aes_ctx_t *aes_ctx, aes_block_t block);
void aes_decrypt_block(aes_ctx_t *aes_ctx, aes_block_t block);

void aes_round_encrypt_block(aes_matrix_t block, aes_matrix_t round_key);
void aes_round_decrypt_block(aes_matrix_t block, aes_matrix_t round_key);

// block <-> matrix
void block_to_matrix(aes_matrix_t matrix, const aes_block_t block);
void matrix_to_block(aes_block_t block, const aes_matrix_t matrix);

// xor
void aes_xor_block(aes_block_t to_xor, const aes_block_t xor_by);

// padding
aes_block_t *aes_pad(const uint8_t *data, size_t len, size_t *nb_blocks);
uint8_t *aes_unpad(const aes_block_t *blocks, size_t nb_blocks, size_t *len);
int aes_unpad_buffer(aes_block_t *blocks, size_t nb_blocks, size_t *len);

// round keys
uint8_t gen_next_rcon(uint8_t rcon);
void gen_next_round_key(
    aes_matrix_t round_key, aes_matrix_t prev_round_key, uint8_t rcon);
void aes_key_expansion(aes_expended_key_t round_keys, enum aes_key_len key_len,
    const aes_key_t key, size_t nb_rounds);

#endif /* !AES_TOOLS_H_ */