/*
** EPITECH PROJECT, 2021
** TESTS_AES_CBC_128
** File description:
** Test aes_cbc_128
*/

#include <criterion/criterion.h>

#include "aes.h"

Test(aes_encrypt, basic_cbc_128)
{
    char msg[] = "Hello from my super AES library";
    aes_key128_t key = "0123456789abcdef";
    aes_iv_t iv = "abcdefghijklmnop";
    uint8_t *enc;
    size_t len_enc;
    uint8_t expected_enc[] =
        "\x3e\x20\x62\x9c\x56\x8d\x0a\x9d\xda\xe8\x67\x6c\x33\x1f\x4b\x58\x36"
        "\xbf\x73\x8c\x7f\x8f\xc3\x65\x28\x7f\x56\x85\x2e\x3f\x40\xbe";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_128, key, iv);
    enc = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_enc);
    cr_assert_not_null(enc);
    cr_expect_eq(len_enc, 32);
    cr_assert_eq(memcmp(enc, expected_enc, len_enc), 0);
    free(enc);
}

Test(aes_encrypt, basic_cbc_128_null_msg)
{
    char msg[] = "";
    aes_key128_t key = "0123456789abcdef";
    aes_iv_t iv = "abcdefghijklmnop";
    uint8_t *enc;
    size_t len_enc;
    uint8_t expected_enc[] =
        "\x81\xd8\x5e\xb7\x15\x72\x54\x63\x88\xaf\x4c\x0c\x3d\x63\x79\x14";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_128, key, iv);
    enc = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_enc);
    cr_assert_not_null(enc);
    cr_expect_eq(len_enc, 16);
    cr_assert_eq(memcmp(enc, expected_enc, len_enc), 0);
    free(enc);
}

Test(aes_encrypt, basic_cbc_128_null_key)
{
    char msg[] = "Hello from my super AES library";
    aes_key128_t key = { 0 };
    aes_iv_t iv = "abcdefghijklmnop";
    uint8_t *enc;
    size_t len_enc;
    uint8_t expected_enc[] =
        "\x41\xa7\xb3\x91\x16\x41\x71\x62\xe4\x9f\xc9\xf7\x9e\xc7\x51\xf2\xaf"
        "\xeb\xef\x70\x5c\x03\x9e\x8d\x25\xe9\xf5\x87\xe3\xfe\xaf\x40";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_128, key, iv);
    enc = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_enc);
    cr_assert_not_null(enc);
    cr_expect_eq(len_enc, 32);
    cr_assert_eq(memcmp(enc, expected_enc, len_enc), 0);
    free(enc);
}

Test(aes_encrypt, basic_cbc_128_null_iv)
{
    char msg[] = "Hello from my super AES library";
    aes_key128_t key = "0123456789abcdef";
    aes_iv_t iv = { 0 };
    uint8_t *enc;
    size_t len_enc;
    uint8_t expected_enc[] =
        "\x5c\x55\x73\xb3\xed\xf8\x79\x3f\xb4\xda\x48\x50\x24\xe0\x47\x71\xf7"
        "\x61\xab\x66\x18\x90\xf7\xf6\xa5\x77\x13\x7c\xab\x2c\x8e\x85";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_128, key, iv);
    enc = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_enc);
    cr_assert_not_null(enc);
    cr_expect_eq(len_enc, 32);
    cr_assert_eq(memcmp(enc, expected_enc, len_enc), 0);
    free(enc);
}

Test(aes_encrypt, basic_cbc_128_null_msg_key_iv)
{
    char msg[] = "";
    aes_key128_t key = { 0 };
    aes_iv_t iv = { 0 };
    uint8_t *enc;
    size_t len_enc;
    uint8_t expected_enc[] =
        "\x01\x43\xdb\x63\xee\x66\xb0\xcd\xff\x9f\x69\x91\x76\x80\x15\x1e";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_128, key, iv);
    enc = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_enc);
    cr_assert_not_null(enc);
    cr_expect_eq(len_enc, 16);
    cr_assert_eq(memcmp(enc, expected_enc, len_enc), 0);
    free(enc);
}

Test(aes_decrypt, basic_cbc_128)
{
    uint8_t enc[] =
        "\x3e\x20\x62\x9c\x56\x8d\x0a\x9d\xda\xe8\x67\x6c\x33\x1f\x4b\x58\x36"
        "\xbf\x73\x8c\x7f\x8f\xc3\x65\x28\x7f\x56\x85\x2e\x3f\x40\xbe";
    aes_key128_t key = "0123456789abcdef";
    aes_iv_t iv = "abcdefghijklmnop";
    uint8_t *msg;
    size_t len_msg;
    char expected_msg[] = "Hello from my super AES library";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_128, key, iv);
    msg = aes_decrypt(&aes, enc, 32, &len_msg);
    cr_assert_not_null(msg);
    cr_expect_eq(len_msg, strlen(expected_msg));
    cr_assert_eq(memcmp(msg, expected_msg, len_msg), 0);
    free(msg);
}

Test(aes_decrypt, basic_cbc_128_null_msg)
{
    uint8_t enc[] =
        "\x81\xd8\x5e\xb7\x15\x72\x54\x63\x88\xaf\x4c\x0c\x3d\x63\x79\x14";
    aes_key128_t key = "0123456789abcdef";
    aes_iv_t iv = "abcdefghijklmnop";
    uint8_t *msg;
    size_t len_msg;
    char expected_msg[] = "";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_128, key, iv);
    msg = aes_decrypt(&aes, enc, 16, &len_msg);
    cr_assert_not_null(msg);
    cr_expect_eq(len_msg, strlen(expected_msg));
    cr_assert_eq(memcmp(msg, expected_msg, len_msg), 0);
    free(msg);
}

Test(aes_decrypt, basic_cbc_128_null_key)
{
    uint8_t enc[] =
        "\x41\xa7\xb3\x91\x16\x41\x71\x62\xe4\x9f\xc9\xf7\x9e\xc7\x51\xf2\xaf"
        "\xeb\xef\x70\x5c\x03\x9e\x8d\x25\xe9\xf5\x87\xe3\xfe\xaf\x40";
    aes_key128_t key = { 0 };
    aes_iv_t iv = "abcdefghijklmnop";
    uint8_t *msg;
    size_t len_msg;
    char expected_msg[] = "Hello from my super AES library";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_128, key, iv);
    msg = aes_decrypt(&aes, enc, 32, &len_msg);
    cr_assert_not_null(msg);
    cr_expect_eq(len_msg, strlen(expected_msg));
    cr_assert_eq(memcmp(msg, expected_msg, len_msg), 0);
    free(msg);
}

Test(aes_decrypt, basic_cbc_128_null_iv)
{
    uint8_t enc[] =
        "\x5c\x55\x73\xb3\xed\xf8\x79\x3f\xb4\xda\x48\x50\x24\xe0\x47\x71\xf7"
        "\x61\xab\x66\x18\x90\xf7\xf6\xa5\x77\x13\x7c\xab\x2c\x8e\x85";
    aes_key128_t key = "0123456789abcdef";
    aes_iv_t iv = { 0 };
    uint8_t *msg;
    size_t len_msg;
    char expected_msg[] = "Hello from my super AES library";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_128, key, iv);
    msg = aes_decrypt(&aes, enc, 32, &len_msg);
    cr_assert_not_null(msg);
    cr_expect_eq(len_msg, strlen(expected_msg));
    cr_assert_eq(memcmp(msg, expected_msg, len_msg), 0);
    free(msg);
}

Test(aes_decrypt, basic_cbc_128_null_msg_key_iv)
{
    uint8_t enc[] =
        "\x01\x43\xdb\x63\xee\x66\xb0\xcd\xff\x9f\x69\x91\x76\x80\x15\x1e";
    aes_key128_t key = { 0 };
    aes_iv_t iv = { 0 };
    uint8_t *msg;
    size_t len_msg;
    char expected_msg[] = "";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_128, key, iv);
    msg = aes_decrypt(&aes, enc, 16, &len_msg);
    cr_assert_not_null(msg);
    cr_expect_eq(len_msg, strlen(expected_msg));
    cr_assert_eq(memcmp(msg, expected_msg, len_msg), 0);
    free(msg);
}