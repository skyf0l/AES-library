/*
** EPITECH PROJECT, 2021
** AES
** File description:
** Aes function
*/

#include <string.h>

#include "aes_init.h"
#include "aes_tools.h"

#include "aes.h"

AES_ADD_INIT_KEY_SIZE(128)
AES_ADD_INIT_KEY_SIZE(192)
AES_ADD_INIT_KEY_SIZE(256)
AES_ADD_INIT_KEY_SIZE(512)
AES_ADD_INIT_KEY_SIZE(1024)
AES_ADD_INIT_KEY_SIZE(2048)
AES_ADD_INIT_KEY_SIZE(4096)

void aes_ctx_init(aes_ctx_t *aes_ctx, enum aes_key_len key_len,
    const aes_key_t key, enum aes_type type)
{
    memset(aes_ctx, 0, sizeof(aes_ctx_t));
    aes_ctx->type = type;
    if (aes_ctx->type == AES_CBC)
        aes_gen_random_iv(aes_ctx->iv);
    aes_change_key(aes_ctx, key_len, key);
}

void aes_ctx_init_cbc_iv(aes_ctx_t *aes_ctx, enum aes_key_len key_len,
    const aes_key_t key, const aes_iv_t iv)
{
    memset(aes_ctx, 0, sizeof(aes_ctx_t));
    aes_ctx->type = AES_CBC;
    aes_change_iv(aes_ctx, iv);
    aes_change_key(aes_ctx, key_len, key);
}