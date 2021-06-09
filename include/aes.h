/*
** EPITECH PROJECT, 2021
** AES
** File description:
** Aes header
*/

#ifndef AES_H_
#define AES_H_

#include <stddef.h>
#include <stdint.h>

#include "aes_init.h"

#define AES_BLOCK_SIZE (128 / 8)

#define AES_KEY_BLOCK_SIZE (4)
#define AES_MAX_KEY_SIZE (4096 / 8)
#define AES_MAX_NB_ROUNDS (134)

#define AES128_KEY_SIZE (128 / 8)
#define AES192_KEY_SIZE (192 / 8)
#define AES256_KEY_SIZE (256 / 8)
#define AES512_KEY_SIZE (512 / 8)
#define AES1024_KEY_SIZE (1024 / 8)
#define AES2048_KEY_SIZE (2048 / 8)
#define AES4096_KEY_SIZE (4096 / 8)

#define AES128_NB_ROUNDS (10)
#define AES192_NB_ROUNDS (12)
#define AES256_NB_ROUNDS (14)
#define AES512_NB_ROUNDS (22)
#define AES1024_NB_ROUNDS (38)
#define AES2048_NB_ROUNDS (70)
#define AES4096_NB_ROUNDS (134)

static const uint32_t AES_KEY_NR_MAP[][2] = {
    { AES128_KEY_SIZE, AES128_NB_ROUNDS },
    { AES192_KEY_SIZE, AES192_NB_ROUNDS },
    { AES256_KEY_SIZE, AES256_NB_ROUNDS },
    { AES512_KEY_SIZE, AES512_NB_ROUNDS },
    { AES1024_KEY_SIZE, AES1024_NB_ROUNDS },
    { AES2048_KEY_SIZE, AES2048_NB_ROUNDS },
    { AES4096_KEY_SIZE, AES4096_NB_ROUNDS },
    { 0, 0 },
};

static const uint8_t AES_INIT_RCON = 0x8d;

typedef uint8_t aes_block_t[AES_BLOCK_SIZE];
typedef uint8_t aes_iv_t[AES_BLOCK_SIZE];
typedef uint8_t aes_key_t[AES_MAX_KEY_SIZE];

typedef uint8_t aes_key_block_t[AES_KEY_BLOCK_SIZE];
typedef aes_key_block_t aes_matrix_t[AES_KEY_BLOCK_SIZE];
typedef aes_matrix_t aes_expended_key_t[AES_MAX_NB_ROUNDS + 1];

typedef uint8_t aes_key128_t[AES128_KEY_SIZE];
typedef uint8_t aes_key192_t[AES192_KEY_SIZE];
typedef uint8_t aes_key256_t[AES256_KEY_SIZE];
typedef uint8_t aes_key512_t[AES512_KEY_SIZE];
typedef uint8_t aes_key1024_t[AES1024_KEY_SIZE];
typedef uint8_t aes_key2048_t[AES2048_KEY_SIZE];
typedef uint8_t aes_key4096_t[AES4096_KEY_SIZE];

enum aes_type {
    AES_ECB,
    AES_CBC,
};

enum aes_key_len {
    AES_128 = AES128_KEY_SIZE,
    AES_192 = AES192_KEY_SIZE,
    AES_256 = AES256_KEY_SIZE,
    AES_512 = AES512_KEY_SIZE,
    AES_1024 = AES1024_KEY_SIZE,
    AES_2048 = AES2048_KEY_SIZE,
    AES_4096 = AES4096_KEY_SIZE,
};

typedef struct aes_ctx {
    enum aes_type type;
    uint32_t key_len;
    aes_key_t key;
    aes_iv_t iv;
    size_t nb_rounds;
    aes_expended_key_t extended_key;
} aes_ctx_t;

// random
int aes_gen_random_key(enum aes_key_len key_len, aes_key_t key);
int aes_gen_random_iv(aes_iv_t iv);

// init
void aes_ctx_init(aes_ctx_t *aes_ctx, enum aes_key_len key_len,
    const aes_key_t key, enum aes_type type);
void aes_ctx_init_cbc_iv(aes_ctx_t *aes_ctx, enum aes_key_len key_len,
    const aes_key_t key, const aes_iv_t iv);

AES_ADD_INIT_KEY_SIZE_PROTOTYPE(128)
AES_ADD_INIT_KEY_SIZE_PROTOTYPE(192)
AES_ADD_INIT_KEY_SIZE_PROTOTYPE(256)
AES_ADD_INIT_KEY_SIZE_PROTOTYPE(512)
AES_ADD_INIT_KEY_SIZE_PROTOTYPE(1024)
AES_ADD_INIT_KEY_SIZE_PROTOTYPE(2048)
AES_ADD_INIT_KEY_SIZE_PROTOTYPE(4096)

// change key / iv
void aes_change_key(
    aes_ctx_t *aes_ctx, enum aes_key_len key_len, const aes_key_t key);
void aes_change_iv(aes_ctx_t *aes_ctx, const aes_iv_t iv);

// encrypt / decrypt
uint8_t *aes_encrypt(aes_ctx_t *aes_ctx, const uint8_t *plain, size_t len_plain,
    size_t *len_enc);
uint8_t *aes_decrypt(
    aes_ctx_t *aes_ctx, const uint8_t *enc, size_t len_enc, size_t *len_plain);

#endif /* !AES_H_ */