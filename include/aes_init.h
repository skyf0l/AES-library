/*
** EPITECH PROJECT, 2021
** AES_INIT
** File description:
** Aes_init header
*/

#ifndef AES_INIT_H_
#define AES_INIT_H_

#define AES_ADD_INIT_KEY_SIZE_PROTOTYPE(key_size)                              \
    void aes_##key_size##_init(aes_ctx_t *aes_ctx,                             \
        const aes_key##key_size##_t key, enum aes_type type);                  \
    void aes_##key_size##_init_cbc_iv(aes_ctx_t *aes_ctx,                      \
        const aes_key##key_size##_t key, const aes_iv_t iv);

#define AES_ADD_INIT_KEY_SIZE(key_size)                                        \
    void aes_##key_size##_init(aes_ctx_t *aes_ctx,                             \
        const aes_key##key_size##_t key, enum aes_type type)                   \
    {                                                                          \
        memset(aes_ctx, 0, sizeof(aes_ctx_t));                                 \
        aes_ctx->type = type;                                                  \
        if (aes_ctx->type == AES_CBC)                                          \
            aes_gen_random_iv(aes_ctx->iv);                                    \
        aes_change_key(aes_ctx, key_size / 8, key);                            \
    }                                                                          \
    void aes_##key_size##_init_cbc_iv(aes_ctx_t *aes_ctx,                      \
        const aes_key##key_size##_t key, const aes_iv_t iv)                    \
    {                                                                          \
        memset(aes_ctx, 0, sizeof(aes_ctx_t));                                 \
        aes_ctx->type = AES_CBC;                                               \
        aes_change_iv(aes_ctx, iv);                                            \
        aes_change_key(aes_ctx, key_size / 8, key);                            \
    }

#endif /* !AES_INIT_H_ */