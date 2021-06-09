/*
** EPITECH PROJECT, 2021
** AES_DECRYPT
** File description:
** Aes_decrypt function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aes_matrix.h"
#include "aes_tools.h"

#include "aes.h"

uint8_t *aes_decrypt(
    aes_ctx_t *aes_ctx, const uint8_t *enc, size_t len_enc, size_t *len_plain)
{
    size_t nb_blocks = len_enc / AES_BLOCK_SIZE;
    aes_block_t *blocks;

    if (len_enc % AES_BLOCK_SIZE != 0)
        return NULL;
    blocks = malloc(sizeof(aes_block_t) * nb_blocks);
    if (!blocks)
        return NULL;
    memcpy(blocks, enc, len_enc);
    for (int k = nb_blocks - 1; k >= 0; k--) {
        aes_decrypt_block(aes_ctx, blocks[k]);
        if (aes_ctx->type == AES_CBC)
            aes_xor_block(blocks[k], (k == 0) ? aes_ctx->iv : blocks[k - 1]);
    }
    if (aes_unpad_buffer(blocks, nb_blocks, len_plain)) {
        free(blocks);
        return NULL;
    }
    return (uint8_t *) blocks;
}

void aes_decrypt_block(aes_ctx_t *aes_ctx, aes_block_t block)
{
    aes_matrix_t block_matrix;

    memcpy(block_matrix, block, AES_BLOCK_SIZE);
    matrix_add_round_key(
        block_matrix, aes_ctx->extended_key[aes_ctx->nb_rounds]);
    matrix_inv_shift_rows(block_matrix);
    matrix_inv_sub_bytes(block_matrix);
    for (size_t round = aes_ctx->nb_rounds - 1; round > 0; round--)
        aes_round_decrypt_block(block_matrix, aes_ctx->extended_key[round]);
    matrix_add_round_key(block_matrix, aes_ctx->extended_key[0]);
    memcpy(block, block_matrix, AES_BLOCK_SIZE);
}

void aes_round_decrypt_block(aes_matrix_t block, aes_matrix_t round_key)
{
    matrix_add_round_key(block, round_key);
    matrix_inv_mix_columns(block);
    matrix_inv_shift_rows(block);
    matrix_inv_sub_bytes(block);
}