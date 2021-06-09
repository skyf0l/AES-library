/*
** EPITECH PROJECT, 2021
** TESTS_AES_ECB_128
** File description:
** Test aes_ecb_128
*/

#include <criterion/criterion.h>

#include "aes.h"

Test(aes_encrypt, ecb_128)
{
    char msg[] = "Hello from my super AES library";
    aes_key128_t key = "0123456789abcdef";
    uint8_t *enc;
    size_t len_enc;
    uint8_t expected_enc[] =
        "\x5c\x55\x73\xb3\xed\xf8\x79\x3f\xb4\xda\x48\x50\x24\xe0\x47\x71\x5e"
        "\x69\x7b\x46\x41\x59\x4c\x3e\xb0\xfc\xd7\x61\x24\x8b\xd8\x51";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_128, key, AES_ECB);
    enc = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_enc);
    cr_assert_not_null(enc);
    cr_expect_eq(len_enc, 32);
    cr_assert_eq(memcmp(enc, expected_enc, len_enc), 0);
    free(enc);
}

Test(aes_encrypt, ecb_128_null_key)
{
    char msg[] = "Hello from my super AES library";
    aes_key128_t key = { 0 };
    uint8_t *enc;
    size_t len_enc;
    uint8_t expected_enc[] =
        "\x1d\x93\x6c\x73\x57\x03\x74\x14\xc1\xfa\x97\x5c\x10\x7e\x63\x53\xd2"
        "\xf9\x7d\x22\xa3\x21\xc4\x03\x21\x34\x70\xd7\x43\x44\x04\x30";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_128, key, AES_ECB);
    enc = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_enc);
    cr_assert_not_null(enc);
    cr_expect_eq(len_enc, 32);
    cr_assert_eq(memcmp(enc, expected_enc, len_enc), 0);
    free(enc);
}

Test(aes_encrypt, ecb_128_null_msg)
{
    char msg[] = "";
    aes_key128_t key = "0123456789abcdef";
    uint8_t *enc;
    size_t len_enc;
    uint8_t expected_enc[] =
        "\x37\x72\x22\xe0\x61\xa9\x24\xc5\x91\xcd\x9c\x27\xea\x16\x3e\xd4";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_128, key, AES_ECB);
    enc = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_enc);
    cr_assert_not_null(enc);
    cr_expect_eq(len_enc, 16);
    cr_assert_eq(memcmp(enc, expected_enc, len_enc), 0);
    free(enc);
}

Test(aes_encrypt, ecb_128_null_key_and_msg)
{
    char msg[] = "";
    aes_key128_t key = { 0 };
    uint8_t *enc;
    size_t len_enc;
    uint8_t expected_enc[] =
        "\x01\x43\xdb\x63\xee\x66\xb0\xcd\xff\x9f\x69\x91\x76\x80\x15\x1e";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_128, key, AES_ECB);
    enc = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_enc);
    cr_assert_not_null(enc);
    cr_expect_eq(len_enc, 16);
    cr_assert_eq(memcmp(enc, expected_enc, len_enc), 0);
    free(enc);
}

Test(aes_decrypt, ecb_128)
{
    uint8_t enc[] =
        "\x5c\x55\x73\xb3\xed\xf8\x79\x3f\xb4\xda\x48\x50\x24\xe0\x47\x71\x5e"
        "\x69\x7b\x46\x41\x59\x4c\x3e\xb0\xfc\xd7\x61\x24\x8b\xd8\x51";
    aes_key128_t key = "0123456789abcdef";
    uint8_t *msg;
    size_t len_msg;
    char expected_msg[] = "Hello from my super AES library";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_128, key, AES_ECB);
    msg = aes_decrypt(&aes, enc, 32, &len_msg);
    cr_assert_not_null(msg);
    cr_expect_eq(len_msg, strlen(expected_msg));
    cr_assert_eq(memcmp(msg, expected_msg, len_msg), 0);
    free(msg);
}

Test(aes_decrypt, ecb_128_null_key)
{
    uint8_t enc[] =
        "\x1d\x93\x6c\x73\x57\x03\x74\x14\xc1\xfa\x97\x5c\x10\x7e\x63\x53\xd2"
        "\xf9\x7d\x22\xa3\x21\xc4\x03\x21\x34\x70\xd7\x43\x44\x04\x30";
    aes_key128_t key = { 0 };
    uint8_t *msg;
    size_t len_msg;
    char expected_msg[] = "Hello from my super AES library";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_128, key, AES_ECB);
    msg = aes_decrypt(&aes, enc, 32, &len_msg);
    cr_assert_not_null(msg);
    cr_expect_eq(len_msg, strlen(expected_msg));
    cr_assert_eq(memcmp(msg, expected_msg, len_msg), 0);
    free(msg);
}

Test(aes_decrypt, ecb_128_null_msg)
{
    uint8_t enc[] =
        "\x37\x72\x22\xe0\x61\xa9\x24\xc5\x91\xcd\x9c\x27\xea\x16\x3e\xd4";
    aes_key128_t key = "0123456789abcdef";
    uint8_t *msg;
    size_t len_msg;
    char expected_msg[] = "";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_128, key, AES_ECB);
    msg = aes_decrypt(&aes, enc, 16, &len_msg);
    cr_assert_not_null(msg);
    cr_expect_eq(len_msg, strlen(expected_msg));
    cr_assert_eq(memcmp(msg, expected_msg, len_msg), 0);
    free(msg);
}

Test(aes_decrypt, ecb_128_null_key_and_msg)
{
    uint8_t enc[] =
        "\x01\x43\xdb\x63\xee\x66\xb0\xcd\xff\x9f\x69\x91\x76\x80\x15\x1e";
    aes_key128_t key = { 0 };
    uint8_t *msg;
    size_t len_msg;
    char expected_msg[] = "";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_128, key, AES_ECB);
    msg = aes_decrypt(&aes, enc, 16, &len_msg);
    cr_assert_not_null(msg);
    cr_expect_eq(len_msg, strlen(expected_msg));
    cr_assert_eq(memcmp(msg, expected_msg, len_msg), 0);
    free(msg);
}