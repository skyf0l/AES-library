/*
** EPITECH PROJECT, 2021
** TESTS_AES_INIT
** File description:
** Test aes_init
*/

#include <criterion/criterion.h>

#include "aes.h"

Test(aes_ctx_init, create_ecb_init)
{
    aes_key128_t key = "0123456789abcdef";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_128, key, AES_ECB);
    cr_assert_eq(aes.type, AES_ECB);
    cr_assert_eq(memcmp(aes.key, "0123456789abcdef", AES128_KEY_SIZE), 0);
}

Test(aes_ctx_init, create_ecb_init_with_small_key)
{
    aes_key128_t key = "0123456789";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_128, key, AES_ECB);
    cr_assert_eq(memcmp(aes.key, "0123456789\0\0\0\0\0\0", AES128_KEY_SIZE), 0);
}

Test(aes_ctx_init, create_cbc_init)
{
    aes_key128_t key = "0123456789abcdef";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_128, key, AES_CBC);
    cr_assert_eq(aes.type, AES_CBC);
    cr_assert_eq(memcmp(aes.key, "0123456789abcdef", AES128_KEY_SIZE), 0);
}

Test(aes_ctx_init, create_cbc_init_with_small_key)
{
    aes_key128_t key = "0123456789";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_128, key, AES_CBC);
    cr_assert_eq(aes.type, AES_CBC);
    cr_assert_eq(memcmp(aes.key, "0123456789\0\0\0\0\0\0", AES128_KEY_SIZE), 0);
    cr_assert(memcmp(aes.iv, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", AES_BLOCK_SIZE));
}

Test(aes_ctx_init_cbc_iv, create_cbc_init_iv)
{
    aes_key128_t key = "0123456789abcdef";
    aes_iv_t iv = "abcdefghijklmnop";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_128, key, iv);
    cr_assert_eq(aes.type, AES_CBC);
    cr_assert_eq(memcmp(aes.key, "0123456789abcdef", AES128_KEY_SIZE), 0);
    cr_assert_eq(memcmp(aes.iv, "abcdefghijklmnop", AES_BLOCK_SIZE), 0);
}

Test(aes_ctx_init_cbc_iv, create_cbc_init_random)
{
    aes_key128_t key;
    aes_iv_t iv;
    aes_ctx_t aes;

    aes_gen_random_key(AES_128, key);
    aes_gen_random_iv(iv);
    aes_ctx_init_cbc_iv(&aes, AES_128, key, iv);
    cr_assert_eq(aes.type, AES_CBC);
    cr_assert_eq(memcmp(aes.key, key, AES128_KEY_SIZE), 0);
    cr_assert_eq(memcmp(aes.iv, iv, AES_BLOCK_SIZE), 0);
}

Test(aes_128_init, create_ecb_init)
{
    aes_key128_t key = "0123456789abcdef";
    aes_ctx_t aes;

    aes_128_init(&aes, key, AES_ECB);
    cr_assert_eq(aes.type, AES_ECB);
    cr_assert_eq(memcmp(aes.key, "0123456789abcdef", AES128_KEY_SIZE), 0);
}

Test(aes_128_init, create_ecb_init_with_small_key)
{
    aes_key128_t key = "0123456789";
    aes_ctx_t aes;

    aes_128_init(&aes, key, AES_ECB);
    cr_assert_eq(memcmp(aes.key, "0123456789\0\0\0\0\0\0", AES128_KEY_SIZE), 0);
}

Test(aes_128_init, create_cbc_init)
{
    aes_key128_t key = "0123456789abcdef";
    aes_ctx_t aes;

    aes_128_init(&aes, key, AES_CBC);
    cr_assert_eq(aes.type, AES_CBC);
    cr_assert_eq(memcmp(aes.key, "0123456789abcdef", AES128_KEY_SIZE), 0);
}

Test(aes_128_init, create_cbc_init_with_small_key)
{
    aes_key128_t key = "0123456789";
    aes_ctx_t aes;

    aes_128_init(&aes, key, AES_CBC);
    cr_assert_eq(aes.type, AES_CBC);
    cr_assert_eq(memcmp(aes.key, "0123456789\0\0\0\0\0\0", AES128_KEY_SIZE), 0);
    cr_assert(memcmp(aes.iv, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", AES_BLOCK_SIZE));
}

Test(aes_128_init_cbc_iv, create_cbc_init_iv)
{
    aes_key128_t key = "0123456789abcdef";
    aes_iv_t iv = "abcdefghijklmnop";
    aes_ctx_t aes;

    aes_128_init_cbc_iv(&aes, key, iv);
    cr_assert_eq(aes.type, AES_CBC);
    cr_assert_eq(memcmp(aes.key, "0123456789abcdef", AES128_KEY_SIZE), 0);
    cr_assert_eq(memcmp(aes.iv, "abcdefghijklmnop", AES_BLOCK_SIZE), 0);
}

Test(aes_128_init_cbc_iv, create_cbc_init_random)
{
    aes_key128_t key;
    aes_iv_t iv;
    aes_ctx_t aes;

    aes_gen_random_key(AES_128, key);
    aes_gen_random_iv(iv);
    aes_128_init_cbc_iv(&aes, key, iv);
    cr_assert_eq(aes.type, AES_CBC);
    cr_assert_eq(memcmp(aes.key, key, AES128_KEY_SIZE), 0);
    cr_assert_eq(memcmp(aes.iv, iv, AES_BLOCK_SIZE), 0);
}
