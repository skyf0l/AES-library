/*
** EPITECH PROJECT, 2021
** TESTS_AES_BLOCK_ENC_DEC
** File description:
** Test aes_block_enc_dec
*/

#include <criterion/criterion.h>

#include "tests_aes.h"

#include "aes.h"
#include "aes_tools.h"

Test(aes_encrypt_block, ecb_basic)
{
    aes_key_t key = "0123456789abcdef";
    aes_block_t block = "0123456789abcdef";
    aes_block_t expected_enc_block = { 114, 114, 126, 136, 30, 220, 253, 1, 0,
        167, 24, 104, 121, 9, 181, 101 };
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_128, key, AES_ECB);
    aes_encrypt_block(&aes, block);
    CHECK_BLOCK_EQUALITY(block, expected_enc_block);
}

Test(aes_encrypt_block, ecb_basic_null_block)
{
    aes_key_t key = "0123456789abcdef";
    aes_block_t block = { 0 };
    aes_block_t expected_enc_block = { 11, 155, 21, 218, 75, 68, 160, 245, 21,
        29, 207, 196, 192, 31, 53, 213 };
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_128, key, AES_ECB);
    aes_encrypt_block(&aes, block);
    CHECK_BLOCK_EQUALITY(block, expected_enc_block);
}

Test(aes_encrypt_block, ecb_basic_null_key)
{
    aes_key_t key = { 0 };
    aes_block_t block = "0123456789abcdef";
    aes_block_t expected_enc_block = { 20, 245, 254, 116, 105, 102, 242, 146,
        101, 28, 34, 136, 187, 255, 70, 9 };
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_128, key, AES_ECB);
    aes_encrypt_block(&aes, block);
    CHECK_BLOCK_EQUALITY(block, expected_enc_block);
}

Test(aes_decrypt_block, ecb_basic)
{
    aes_key_t key = "0123456789abcdef";
    aes_block_t block = { 114, 114, 126, 136, 30, 220, 253, 1, 0, 167, 24, 104,
        121, 9, 181, 101 };
    aes_block_t expected_enc_block = "0123456789abcdef";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_128, key, AES_ECB);
    aes_decrypt_block(&aes, block);
    CHECK_BLOCK_EQUALITY(block, expected_enc_block);
}

Test(aes_decrypt_block, ecb_basic_null_block)
{
    aes_key_t key = "0123456789abcdef";
    aes_block_t block = { 11, 155, 21, 218, 75, 68, 160, 245, 21, 29, 207, 196,
        192, 31, 53, 213 };
    aes_block_t expected_enc_block = { 0 };
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_128, key, AES_ECB);
    aes_decrypt_block(&aes, block);
    CHECK_BLOCK_EQUALITY(block, expected_enc_block);
}

Test(aes_decrypt_block, ecb_basic_null_key)
{
    aes_key_t key = { 0 };
    aes_block_t block = { 20, 245, 254, 116, 105, 102, 242, 146, 101, 28, 34,
        136, 187, 255, 70, 9 };
    aes_block_t expected_enc_block = "0123456789abcdef";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_128, key, AES_ECB);
    aes_decrypt_block(&aes, block);
    CHECK_BLOCK_EQUALITY(block, expected_enc_block);
}

Test(aes_encrypt, ecb_block)
{
    aes_key_t key = "0123456789abcdef";
    aes_block_t block = "ARandomMsgPadded";
    aes_block_t expected_enc_block =
        "\x67\x22\x1c\x79\xd7\x87\xf2\x8d\xe7\x61\xf6\xa4\x69\xea\x9f\xdc";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_128, key, AES_ECB);
    aes_encrypt_block(&aes, block);
    for (int k = 0; k < AES_BLOCK_SIZE; k++)
        cr_assert_eq(block[k], expected_enc_block[k]);
}

Test(aes_encrypt_block, ecb_block_null_block)
{
    aes_key_t key = "0123456789abcdef";
    aes_block_t block = { 0 };
    aes_block_t expected_enc_block =
        "\x0b\x9b\x15\xda\x4b\x44\xa0\xf5\x15\x1d\xcf\xc4\xc0\x1f\x35\xd5";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_128, key, AES_ECB);
    aes_encrypt_block(&aes, block);
    for (int k = 0; k < AES_BLOCK_SIZE; k++)
        cr_assert_eq(block[k], expected_enc_block[k]);
}

Test(aes_encrypt_block, ecb_block_null_key)
{
    aes_key_t key = { 0 };
    aes_block_t block = "ARandomMsgPadded";
    aes_block_t expected_enc_block =
        "\x67\x85\xc5\xfa\x28\x59\x9a\x7f\x3e\x1d\x2e\x2f\x53\x19\xdc\x0a";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_128, key, AES_ECB);
    aes_encrypt_block(&aes, block);
    for (int k = 0; k < AES_BLOCK_SIZE; k++)
        cr_assert_eq(block[k], expected_enc_block[k]);
}

Test(aes_encrypt_block, ecb_block_null_key_and_block)
{
    aes_key_t key = { 0 };
    aes_block_t block = { 0 };
    aes_block_t expected_enc_block =
        "\x66\xe9\x4b\xd4\xef\x8a\x2c\x3b\x88\x4c\xfa\x59\xca\x34\x2b\x2e";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_128, key, AES_ECB);
    aes_encrypt_block(&aes, block);
    for (int k = 0; k < AES_BLOCK_SIZE; k++)
        cr_assert_eq(block[k], expected_enc_block[k]);
}

Test(aes_decrypt_block, ecb_block_null_block)
{
    aes_key_t key = "0123456789abcdef";
    aes_block_t block =
        "\x0b\x9b\x15\xda\x4b\x44\xa0\xf5\x15\x1d\xcf\xc4\xc0\x1f\x35\xd5";
    aes_block_t expected_enc_block = { 0 };
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_128, key, AES_ECB);
    aes_decrypt_block(&aes, block);
    for (int k = 0; k < AES_BLOCK_SIZE; k++)
        cr_assert_eq(block[k], expected_enc_block[k]);
}

Test(aes_decrypt_block, ecb_block_null_key)
{
    aes_key_t key = { 0 };
    aes_block_t block =
        "\x67\x85\xc5\xfa\x28\x59\x9a\x7f\x3e\x1d\x2e\x2f\x53\x19\xdc\x0a";
    aes_block_t expected_enc_block = "ARandomMsgPadded";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_128, key, AES_ECB);
    aes_decrypt_block(&aes, block);
    for (int k = 0; k < AES_BLOCK_SIZE; k++)
        cr_assert_eq(block[k], expected_enc_block[k]);
}

Test(aes_decrypt_block, ecb_block_null_key_and_block)
{
    aes_key_t key = { 0 };
    aes_block_t block =
        "\x66\xe9\x4b\xd4\xef\x8a\x2c\x3b\x88\x4c\xfa\x59\xca\x34\x2b\x2e";
    aes_block_t expected_enc_block = { 0 };
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_128, key, AES_ECB);
    aes_decrypt_block(&aes, block);
    for (int k = 0; k < AES_BLOCK_SIZE; k++)
        cr_assert_eq(block[k], expected_enc_block[k]);
}