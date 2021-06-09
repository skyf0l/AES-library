/*
** EPITECH PROJECT, 2021
** AES_ENCRYPT
** File description:
** Aes_encrypt function
*/

#include <stdlib.h>
#include <string.h>

#include "aes_matrix.h"
#include "aes_tools.h"

#include "aes.h"

uint8_t *aes_encrypt(
    aes_ctx_t *aes_ctx, const uint8_t *plain, size_t len_plain, size_t *len_enc)
{
    size_t nb_blocks;
    aes_block_t *blocks = aes_pad(plain, len_plain, &nb_blocks);

    if (!blocks)
        return NULL;
    *len_enc = nb_blocks * AES_BLOCK_SIZE;
    for (size_t k = 0; k < nb_blocks; k++) {
        if (aes_ctx->type == AES_CBC && k != 0)
            aes_xor_block(blocks[k], blocks[k - 1]);
        else if (aes_ctx->type == AES_CBC && k == 0)
            aes_xor_block(blocks[k], aes_ctx->iv);
        aes_encrypt_block(aes_ctx, blocks[k]);
    }
    return (uint8_t *) blocks;
}

void aes_encrypt_block(aes_ctx_t *aes_ctx, aes_block_t block)
{
    aes_matrix_t block_matrix;

    memcpy(block_matrix, block, AES_BLOCK_SIZE);
    matrix_add_round_key(block_matrix, aes_ctx->extended_key[0]);
    for (size_t k = 1; k < aes_ctx->nb_rounds; k++)
        aes_round_encrypt_block(block_matrix, aes_ctx->extended_key[k]);
    matrix_sub_bytes(block_matrix);
    matrix_shift_rows(block_matrix);
    matrix_add_round_key(
        block_matrix, aes_ctx->extended_key[aes_ctx->nb_rounds]);
    memcpy(block, block_matrix, AES_BLOCK_SIZE);
}

void aes_round_encrypt_block(aes_matrix_t block, aes_matrix_t round_key)
{
    matrix_sub_bytes(block);
    matrix_shift_rows(block);
    matrix_mix_columns(block);
    matrix_add_round_key(block, round_key);
}