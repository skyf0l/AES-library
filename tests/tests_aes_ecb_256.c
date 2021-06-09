/*
** EPITECH PROJECT, 2021
** TESTS_AES_ECB_256
** File description:
** Test aes_ecb_256
*/

#include <criterion/criterion.h>

#include "aes.h"

Test(aes_encrypt, ecb_256)
{
    char msg[] = "Hello from my super AES library";
    aes_key256_t key = "0123456789abcdefghijklmnopqrstuv";
    uint8_t *enc;
    size_t len_enc;
    uint8_t expected_enc[] =
        "\xa3\xc8\x00\x65\x37\xda\x80\x00\x14\xec\x19\x17\x4d\xd6\xe9\xbe\x9c"
        "\xcc\x64\x8d\x5f\x15\x33\x01\x25\x8f\xb0\x4e\x50\x1d\x1b\x18";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_256, key, AES_ECB);
    enc = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_enc);
    cr_assert_not_null(enc);
    cr_expect_eq(len_enc, 32);
    cr_assert_eq(memcmp(enc, expected_enc, len_enc), 0);
    free(enc);
}

Test(aes_encrypt, ecb_256_null_key)
{
    char msg[] = "Hello from my super AES library";
    aes_key256_t key = { 0 };
    uint8_t *enc;
    size_t len_enc;
    uint8_t expected_enc[] =
        "\x4e\x1a\x39\x23\x0f\x62\x20\xbd\xc5\x44\xab\x18\xd3\x7e\x79\xd1\x64"
        "\xd4\x35\xcd\x94\x60\x94\x6b\x38\x8b\xbe\x3b\x0a\xda\xf3\x6d";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_256, key, AES_ECB);
    enc = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_enc);
    cr_assert_not_null(enc);
    cr_expect_eq(len_enc, 32);
    cr_assert_eq(memcmp(enc, expected_enc, len_enc), 0);
    free(enc);
}

Test(aes_encrypt, ecb_256_null_msg)
{
    char msg[] = "";
    aes_key256_t key = "0123456789abcdefghijklmnopqrstuv";
    uint8_t *enc;
    size_t len_enc;
    uint8_t expected_enc[] =
        "\xcc\xa1\x89\x72\x7d\x3e\x24\xb3\x54\x0a\x08\xa8\x90\xa9\x42\x53";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_256, key, AES_ECB);
    enc = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_enc);
    cr_assert_not_null(enc);
    cr_expect_eq(len_enc, 16);
    cr_assert_eq(memcmp(enc, expected_enc, len_enc), 0);
    free(enc);
}

Test(aes_encrypt, ecb_256_null_key_and_msg)
{
    char msg[] = "";
    aes_key256_t key = { 0 };
    uint8_t *enc;
    size_t len_enc;
    uint8_t expected_enc[] =
        "\x1f\x78\x8f\xe6\xd8\x6c\x31\x75\x49\x69\x7f\xbf\x0c\x07\xfa\x43";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_256, key, AES_ECB);
    enc = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_enc);
    cr_assert_not_null(enc);
    cr_expect_eq(len_enc, 16);
    cr_assert_eq(memcmp(enc, expected_enc, len_enc), 0);
    free(enc);
}

Test(aes_decrypt, ecb_256)
{
    uint8_t enc[] =
        "\xa3\xc8\x00\x65\x37\xda\x80\x00\x14\xec\x19\x17\x4d\xd6\xe9\xbe\x9c"
        "\xcc\x64\x8d\x5f\x15\x33\x01\x25\x8f\xb0\x4e\x50\x1d\x1b\x18";
    aes_key256_t key = "0123456789abcdefghijklmnopqrstuv";
    uint8_t *msg;
    size_t len_msg;
    char expected_msg[] = "Hello from my super AES library";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_256, key, AES_ECB);
    msg = aes_decrypt(&aes, enc, 32, &len_msg);
    cr_assert_not_null(msg);
    cr_expect_eq(len_msg, strlen(expected_msg));
    cr_assert_eq(memcmp(msg, expected_msg, len_msg), 0);
    free(msg);
}

Test(aes_decrypt, ecb_256_null_key)
{
    uint8_t enc[] =
        "\x4e\x1a\x39\x23\x0f\x62\x20\xbd\xc5\x44\xab\x18\xd3\x7e\x79\xd1\x64"
        "\xd4\x35\xcd\x94\x60\x94\x6b\x38\x8b\xbe\x3b\x0a\xda\xf3\x6d";
    aes_key256_t key = { 0 };
    uint8_t *msg;
    size_t len_msg;
    char expected_msg[] = "Hello from my super AES library";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_256, key, AES_ECB);
    msg = aes_decrypt(&aes, enc, 32, &len_msg);
    cr_assert_not_null(msg);
    cr_expect_eq(len_msg, strlen(expected_msg));
    cr_assert_eq(memcmp(msg, expected_msg, len_msg), 0);
    free(msg);
}

Test(aes_decrypt, ecb_256_null_msg)
{
    uint8_t enc[] =
        "\xcc\xa1\x89\x72\x7d\x3e\x24\xb3\x54\x0a\x08\xa8\x90\xa9\x42\x53";
    aes_key256_t key = "0123456789abcdefghijklmnopqrstuv";
    uint8_t *msg;
    size_t len_msg;
    char expected_msg[] = "";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_256, key, AES_ECB);
    msg = aes_decrypt(&aes, enc, 16, &len_msg);
    cr_assert_not_null(msg);
    cr_expect_eq(len_msg, strlen(expected_msg));
    cr_assert_eq(memcmp(msg, expected_msg, len_msg), 0);
    free(msg);
}

Test(aes_decrypt, ecb_256_null_key_and_msg)
{
    uint8_t enc[] =
        "\x1f\x78\x8f\xe6\xd8\x6c\x31\x75\x49\x69\x7f\xbf\x0c\x07\xfa\x43";
    aes_key256_t key = { 0 };
    uint8_t *msg;
    size_t len_msg;
    char expected_msg[] = "";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_256, key, AES_ECB);
    msg = aes_decrypt(&aes, enc, 16, &len_msg);
    cr_assert_not_null(msg);
    cr_expect_eq(len_msg, strlen(expected_msg));
    cr_assert_eq(memcmp(msg, expected_msg, len_msg), 0);
    free(msg);
}