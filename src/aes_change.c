/*
** EPITECH PROJECT, 2021
** AES_CHANGE
** File description:
** Aes_change function
*/

#include <string.h>

#include "aes_tools.h"

#include "aes.h"

void aes_change_iv(aes_ctx_t *aes_ctx, const aes_iv_t iv)
{
    memmove(aes_ctx->iv, iv, AES_BLOCK_SIZE);
}

void aes_change_key(
    aes_ctx_t *aes_ctx, enum aes_key_len key_len, const aes_key_t key)
{
    aes_ctx->key_len = AES128_KEY_SIZE;
    aes_ctx->nb_rounds = AES128_NB_ROUNDS;
    for (int k = 0; AES_KEY_NR_MAP[k][0]; k++) {
        if (AES_KEY_NR_MAP[k][0] == key_len) {
            aes_ctx->key_len = AES_KEY_NR_MAP[k][0];
            aes_ctx->nb_rounds = AES_KEY_NR_MAP[k][1];
        }
    }
    memmove(aes_ctx->key, key, aes_ctx->key_len);
    aes_key_expansion(aes_ctx->extended_key, aes_ctx->key_len, aes_ctx->key,
        aes_ctx->nb_rounds);
}