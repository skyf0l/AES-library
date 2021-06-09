/*
** EPITECH PROJECT, 2021
** TESTS_AES_CBC_192
** File description:
** Test aes_cbc_192
*/

#include <criterion/criterion.h>

#include "aes.h"

Test(aes_encrypt, basic_cbc_192)
{
    char msg[] = "Hello from my super AES library";
    aes_key192_t key = "0123456789abcdefghijklmn";
    aes_iv_t iv = "abcdefghijklmnop";
    uint8_t *enc;
    size_t len_enc;
    uint8_t expected_enc[] =
        "\x26\xd2\xb6\xb6\xf8\x52\x2e\xd7\x6b\xdd\x8f\x7f\x1d\x1a\xe7\x9d\xaf"
        "\xb0\x63\xc3\xf1\x1f\x4f\xcc\x05\xbb\x25\x70\xbd\xc0\xc1\x17";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_192, key, iv);
    enc = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_enc);
    cr_assert_not_null(enc);
    cr_expect_eq(len_enc, 32);
    cr_assert_eq(memcmp(enc, expected_enc, len_enc), 0);
    free(enc);
}

Test(aes_encrypt, basic_cbc_192_null_msg)
{
    char msg[] = "";
    aes_key192_t key = "0123456789abcdefghijklmn";
    aes_iv_t iv = "abcdefghijklmnop";
    uint8_t *enc;
    size_t len_enc;
    uint8_t expected_enc[] =
        "\xe1\x69\xe0\xe2\x05\xcd\xc2\xba\x89\x5b\x7c\xf6\x09\x76\x73\xb1";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_192, key, iv);
    enc = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_enc);
    cr_assert_not_null(enc);
    cr_expect_eq(len_enc, 16);
    cr_assert_eq(memcmp(enc, expected_enc, len_enc), 0);
    free(enc);
}

Test(aes_encrypt, basic_cbc_192_null_key)
{
    char msg[] = "Hello from my super AES library";
    aes_key192_t key = { 0 };
    aes_iv_t iv = "abcdefghijklmnop";
    uint8_t *enc;
    size_t len_enc;
    uint8_t expected_enc[] =
        "\x41\xcb\xdc\xde\x72\x52\xe6\x63\x12\x5f\xad\xdf\xa0\x68\x8a\x53\x4a"
        "\x71\x3a\x93\x9f\xad\xcf\x5e\x91\xa4\xa0\x0d\x62\xeb\x9d\xe2";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_192, key, iv);
    enc = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_enc);
    cr_assert_not_null(enc);
    cr_expect_eq(len_enc, 32);
    cr_assert_eq(memcmp(enc, expected_enc, len_enc), 0);
    free(enc);
}

Test(aes_encrypt, basic_cbc_192_null_iv)
{
    char msg[] = "Hello from my super AES library";
    aes_key192_t key = "0123456789abcdefghijklmn";
    aes_iv_t iv = { 0 };
    uint8_t *enc;
    size_t len_enc;
    uint8_t expected_enc[] =
        "\x53\x74\xf9\x11\x10\x4f\x83\x4f\x4b\x50\x11\x03\x44\x84\x37\x94\xca"
        "\x41\x8a\x90\xd6\x50\x77\xc7\x0c\x6a\x32\x59\x20\xb6\x5a\x33";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_192, key, iv);
    enc = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_enc);
    cr_assert_not_null(enc);
    cr_expect_eq(len_enc, 32);
    cr_assert_eq(memcmp(enc, expected_enc, len_enc), 0);
    free(enc);
}

Test(aes_encrypt, basic_cbc_192_null_msg_key_iv)
{
    char msg[] = "";
    aes_key192_t key = { 0 };
    aes_iv_t iv = { 0 };
    uint8_t *enc;
    size_t len_enc;
    uint8_t expected_enc[] =
        "\x02\xbb\x29\x25\x27\xe7\x26\xfd\x51\xeb\x29\x89\x4d\x6f\x0a\xad";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_192, key, iv);
    enc = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_enc);
    cr_assert_not_null(enc);
    cr_expect_eq(len_enc, 16);
    cr_assert_eq(memcmp(enc, expected_enc, len_enc), 0);
    free(enc);
}

Test(aes_decrypt, basic_cbc_192)
{
    uint8_t enc[] =
        "\x26\xd2\xb6\xb6\xf8\x52\x2e\xd7\x6b\xdd\x8f\x7f\x1d\x1a\xe7\x9d\xaf"
        "\xb0\x63\xc3\xf1\x1f\x4f\xcc\x05\xbb\x25\x70\xbd\xc0\xc1\x17";
    aes_key192_t key = "0123456789abcdefghijklmn";
    aes_iv_t iv = "abcdefghijklmnop";
    uint8_t *msg;
    size_t len_msg;
    char expected_msg[] = "Hello from my super AES library";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_192, key, iv);
    msg = aes_decrypt(&aes, enc, 32, &len_msg);
    cr_assert_not_null(msg);
    cr_expect_eq(len_msg, strlen(expected_msg));
    cr_assert_eq(memcmp(msg, expected_msg, len_msg), 0);
    free(msg);
}

Test(aes_decrypt, basic_cbc_192_null_msg)
{
    uint8_t enc[] =
        "\xe1\x69\xe0\xe2\x05\xcd\xc2\xba\x89\x5b\x7c\xf6\x09\x76\x73\xb1";
    aes_key192_t key = "0123456789abcdefghijklmn";
    aes_iv_t iv = "abcdefghijklmnop";
    uint8_t *msg;
    size_t len_msg;
    char expected_msg[] = "";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_192, key, iv);
    msg = aes_decrypt(&aes, enc, 16, &len_msg);
    cr_assert_not_null(msg);
    cr_expect_eq(len_msg, strlen(expected_msg));
    cr_assert_eq(memcmp(msg, expected_msg, len_msg), 0);
    free(msg);
}

Test(aes_decrypt, basic_cbc_192_null_key)
{
    uint8_t enc[] =
        "\x41\xcb\xdc\xde\x72\x52\xe6\x63\x12\x5f\xad\xdf\xa0\x68\x8a\x53\x4a"
        "\x71\x3a\x93\x9f\xad\xcf\x5e\x91\xa4\xa0\x0d\x62\xeb\x9d\xe2";
    aes_key192_t key = { 0 };
    aes_iv_t iv = "abcdefghijklmnop";
    uint8_t *msg;
    size_t len_msg;
    char expected_msg[] = "Hello from my super AES library";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_192, key, iv);
    msg = aes_decrypt(&aes, enc, 32, &len_msg);
    cr_assert_not_null(msg);
    cr_expect_eq(len_msg, strlen(expected_msg));
    cr_assert_eq(memcmp(msg, expected_msg, len_msg), 0);
    free(msg);
}

Test(aes_decrypt, basic_cbc_192_null_iv)
{
    uint8_t enc[] =
        "\x53\x74\xf9\x11\x10\x4f\x83\x4f\x4b\x50\x11\x03\x44\x84\x37\x94\xca"
        "\x41\x8a\x90\xd6\x50\x77\xc7\x0c\x6a\x32\x59\x20\xb6\x5a\x33";
    aes_key192_t key = "0123456789abcdefghijklmn";
    aes_iv_t iv = { 0 };
    uint8_t *msg;
    size_t len_msg;
    char expected_msg[] = "Hello from my super AES library";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_192, key, iv);
    msg = aes_decrypt(&aes, enc, 32, &len_msg);
    cr_assert_not_null(msg);
    cr_expect_eq(len_msg, strlen(expected_msg));
    cr_assert_eq(memcmp(msg, expected_msg, len_msg), 0);
    free(msg);
}

Test(aes_decrypt, basic_cbc_192_null_msg_key_iv)
{
    uint8_t enc[] =
        "\x02\xbb\x29\x25\x27\xe7\x26\xfd\x51\xeb\x29\x89\x4d\x6f\x0a\xad";
    aes_key192_t key = { 0 };
    aes_iv_t iv = { 0 };
    uint8_t *msg;
    size_t len_msg;
    char expected_msg[] = "";
    aes_ctx_t aes;

    aes_ctx_init_cbc_iv(&aes, AES_192, key, iv);
    msg = aes_decrypt(&aes, enc, 16, &len_msg);
    cr_assert_not_null(msg);
    cr_expect_eq(len_msg, strlen(expected_msg));
    cr_assert_eq(memcmp(msg, expected_msg, len_msg), 0);
    free(msg);
}