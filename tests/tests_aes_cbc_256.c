/*
** EPITECH PROJECT, 2021
** TESTS_AES_CBC_256
** File description:
** Test aes_cbc_256
*/

#include <criterion/criterion.h>

#include "aes.h"

Test(aes_encrypt, basic_cbc_256)
{
    char msg[] = "Hello from my super AES library";
    aes_key256_t key = "0123456789abcdefghijklmnopqrstuv";
    aes_iv_t iv = "abcdefghijklmnop";
    uint8_t *enc;
    size_t len_enc;
    uint8_t expected_enc[] =
        "\x5f\xd0\xf1\x6e\xf3\x34\xfa\x34\xb2\xe7\x35\xc1\xcd\xe5\x93\xaf\xd3"
        "\x72\x29\xca\xdc\xc3\x0e\x89\x75\x98\x86\x8a\xb7\x24\x2b\x9e";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_256, key, iv);
    enc = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_enc);
    cr_assert_not_null(enc);
    cr_expect_eq(len_enc, 32);
    cr_assert_eq(memcmp(enc, expected_enc, len_enc), 0);
    free(enc);
}

Test(aes_encrypt, basic_cbc_256_null_msg)
{
    char msg[] = "";
    aes_key256_t key = "0123456789abcdefghijklmnopqrstuv";
    aes_iv_t iv = "abcdefghijklmnop";
    uint8_t *enc;
    size_t len_enc;
    uint8_t expected_enc[] =
        "\x4b\xaa\xca\xa0\xd2\x21\x99\xc9\x7d\xe2\x06\xc4\x65\xb7\xb1\x4a";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_256, key, iv);
    enc = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_enc);
    cr_assert_not_null(enc);
    cr_expect_eq(len_enc, 16);
    cr_assert_eq(memcmp(enc, expected_enc, len_enc), 0);
    free(enc);
}

Test(aes_encrypt, basic_cbc_256_null_key)
{
    char msg[] = "Hello from my super AES library";
    aes_key256_t key = { 0 };
    aes_iv_t iv = "abcdefghijklmnop";
    uint8_t *enc;
    size_t len_enc;
    uint8_t expected_enc[] =
        "\x81\xa9\xfd\xb3\x55\x6f\x92\x8f\x9c\x0f\x40\xd4\xe1\x20\x67\xbc\xb4"
        "\x06\x1c\x7d\xb3\x1f\xc4\x68\x97\xfc\x4c\x11\xee\xed\x6c\xdd";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_256, key, iv);
    enc = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_enc);
    cr_assert_not_null(enc);
    cr_expect_eq(len_enc, 32);
    cr_assert_eq(memcmp(enc, expected_enc, len_enc), 0);
    free(enc);
}

Test(aes_encrypt, basic_cbc_256_null_iv)
{
    char msg[] = "Hello from my super AES library";
    aes_key256_t key = "0123456789abcdefghijklmnopqrstuv";
    aes_iv_t iv = { 0 };
    uint8_t *enc;
    size_t len_enc;
    uint8_t expected_enc[] =
        "\xa3\xc8\x00\x65\x37\xda\x80\x00\x14\xec\x19\x17\x4d\xd6\xe9\xbe\xa8"
        "\xe3\x6d\x8f\x94\x3e\xce\xe9\xd1\xbc\xa2\x75\xaa\xd4\x0f\x64";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_256, key, iv);
    enc = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_enc);
    cr_assert_not_null(enc);
    cr_expect_eq(len_enc, 32);
    cr_assert_eq(memcmp(enc, expected_enc, len_enc), 0);
    free(enc);
}

Test(aes_encrypt, basic_cbc_256_null_msg_key_iv)
{
    char msg[] = "";
    aes_key256_t key = { 0 };
    aes_iv_t iv = { 0 };
    uint8_t *enc;
    size_t len_enc;
    uint8_t expected_enc[] =
        "\x1f\x78\x8f\xe6\xd8\x6c\x31\x75\x49\x69\x7f\xbf\x0c\x07\xfa\x43";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_256, key, iv);
    enc = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_enc);
    cr_assert_not_null(enc);
    cr_expect_eq(len_enc, 16);
    cr_assert_eq(memcmp(enc, expected_enc, len_enc), 0);
    free(enc);
}

Test(aes_decrypt, basic_cbc_256)
{
    uint8_t enc[] =
        "\x5f\xd0\xf1\x6e\xf3\x34\xfa\x34\xb2\xe7\x35\xc1\xcd\xe5\x93\xaf\xd3"
        "\x72\x29\xca\xdc\xc3\x0e\x89\x75\x98\x86\x8a\xb7\x24\x2b\x9e";
    aes_key256_t key = "0123456789abcdefghijklmnopqrstuv";
    aes_iv_t iv = "abcdefghijklmnop";
    uint8_t *msg;
    size_t len_msg;
    char expected_msg[] = "Hello from my super AES library";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_256, key, iv);
    msg = aes_decrypt(&aes, enc, 32, &len_msg);
    cr_assert_not_null(msg);
    cr_expect_eq(len_msg, strlen(expected_msg));
    cr_assert_eq(memcmp(msg, expected_msg, len_msg), 0);
    free(msg);
}

Test(aes_decrypt, basic_cbc_256_null_msg)
{
    uint8_t enc[] =
        "\x4b\xaa\xca\xa0\xd2\x21\x99\xc9\x7d\xe2\x06\xc4\x65\xb7\xb1\x4a";
    aes_key256_t key = "0123456789abcdefghijklmnopqrstuv";
    aes_iv_t iv = "abcdefghijklmnop";
    uint8_t *msg;
    size_t len_msg;
    char expected_msg[] = "";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_256, key, iv);
    msg = aes_decrypt(&aes, enc, 16, &len_msg);
    cr_assert_not_null(msg);
    cr_expect_eq(len_msg, strlen(expected_msg));
    cr_assert_eq(memcmp(msg, expected_msg, len_msg), 0);
    free(msg);
}

Test(aes_decrypt, basic_cbc_256_null_key)
{
    uint8_t enc[] =
        "\x81\xa9\xfd\xb3\x55\x6f\x92\x8f\x9c\x0f\x40\xd4\xe1\x20\x67\xbc\xb4"
        "\x06\x1c\x7d\xb3\x1f\xc4\x68\x97\xfc\x4c\x11\xee\xed\x6c\xdd";
    aes_key256_t key = { 0 };
    aes_iv_t iv = "abcdefghijklmnop";
    uint8_t *msg;
    size_t len_msg;
    char expected_msg[] = "Hello from my super AES library";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_256, key, iv);
    msg = aes_decrypt(&aes, enc, 32, &len_msg);
    cr_assert_not_null(msg);
    cr_expect_eq(len_msg, strlen(expected_msg));
    cr_assert_eq(memcmp(msg, expected_msg, len_msg), 0);
    free(msg);
}

Test(aes_decrypt, basic_cbc_256_null_iv)
{
    uint8_t enc[] =
        "\xa3\xc8\x00\x65\x37\xda\x80\x00\x14\xec\x19\x17\x4d\xd6\xe9\xbe\xa8"
        "\xe3\x6d\x8f\x94\x3e\xce\xe9\xd1\xbc\xa2\x75\xaa\xd4\x0f\x64";
    aes_key256_t key = "0123456789abcdefghijklmnopqrstuv";
    aes_iv_t iv = { 0 };
    uint8_t *msg;
    size_t len_msg;
    char expected_msg[] = "Hello from my super AES library";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_256, key, iv);
    msg = aes_decrypt(&aes, enc, 32, &len_msg);
    cr_assert_not_null(msg);
    cr_expect_eq(len_msg, strlen(expected_msg));
    cr_assert_eq(memcmp(msg, expected_msg, len_msg), 0);
    free(msg);
}

Test(aes_decrypt, basic_cbc_256_null_msg_key_iv)
{
    uint8_t enc[] =
        "\x1f\x78\x8f\xe6\xd8\x6c\x31\x75\x49\x69\x7f\xbf\x0c\x07\xfa\x43";
    aes_key256_t key = { 0 };
    aes_iv_t iv = { 0 };
    uint8_t *msg;
    size_t len_msg;
    char expected_msg[] = "";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_256, key, iv);
    msg = aes_decrypt(&aes, enc, 16, &len_msg);
    cr_assert_not_null(msg);
    cr_expect_eq(len_msg, strlen(expected_msg));
    cr_assert_eq(memcmp(msg, expected_msg, len_msg), 0);
    free(msg);
}