/*
** EPITECH PROJECT, 2021
** TESTS_AES_ECB_192
** File description:
** Test aes_ecb_192
*/

#include <criterion/criterion.h>

#include "aes.h"

Test(aes_encrypt, ecb_192)
{
    char msg[] = "Hello from my super AES library";
    aes_key192_t key = "0123456789abcdefghijklmn";
    uint8_t *enc;
    size_t len_enc;
    uint8_t expected_enc[] =
        "\x53\x74\xf9\x11\x10\x4f\x83\x4f\x4b\x50\x11\x03\x44\x84\x37\x94\x67"
        "\x7f\xd1\x70\x09\x5a\xf8\x76\x65\xd9\xb0\xfb\xe2\x55\xeb\x95";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_192, key, AES_ECB);
    enc = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_enc);
    cr_assert_not_null(enc);
    cr_expect_eq(len_enc, 32);
    cr_assert_eq(memcmp(enc, expected_enc, len_enc), 0);
    free(enc);
}

Test(aes_encrypt, ecb_192_null_key)
{
    char msg[] = "Hello from my super AES library";
    aes_key192_t key = { 0 };
    uint8_t *enc;
    size_t len_enc;
    uint8_t expected_enc[] =
        "\x7c\xd7\x2f\x3d\xff\x65\x29\xbc\x7e\xe5\x9a\x1c\x55\x6a\xb6\x21\xf6"
        "\x70\x70\xeb\xcd\x43\xce\x09\xd7\x4b\x75\x07\xe1\xfa\x17\x52";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_192, key, AES_ECB);
    enc = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_enc);
    cr_assert_not_null(enc);
    cr_expect_eq(len_enc, 32);
    cr_assert_eq(memcmp(enc, expected_enc, len_enc), 0);
    free(enc);
}

Test(aes_encrypt, ecb_192_null_msg)
{
    char msg[] = "";
    aes_key192_t key = "0123456789abcdefghijklmn";
    uint8_t *enc;
    size_t len_enc;
    uint8_t expected_enc[] =
        "\x03\x66\x75\xac\x1b\x76\x53\x5b\xc7\x36\x38\x60\xc3\x66\x92\x69";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_192, key, AES_ECB);
    enc = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_enc);
    cr_assert_not_null(enc);
    cr_expect_eq(len_enc, 16);
    cr_assert_eq(memcmp(enc, expected_enc, len_enc), 0);
    free(enc);
}

Test(aes_encrypt, ecb_192_null_key_and_msg)
{
    char msg[] = "";
    aes_key192_t key = { 0 };
    uint8_t *enc;
    size_t len_enc;
    uint8_t expected_enc[] =
        "\x02\xbb\x29\x25\x27\xe7\x26\xfd\x51\xeb\x29\x89\x4d\x6f\x0a\xad";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_192, key, AES_ECB);
    enc = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_enc);
    cr_assert_not_null(enc);
    cr_expect_eq(len_enc, 16);
    cr_assert_eq(memcmp(enc, expected_enc, len_enc), 0);
    free(enc);
}

Test(aes_decrypt, ecb_192)
{
    uint8_t enc[] =
        "\x53\x74\xf9\x11\x10\x4f\x83\x4f\x4b\x50\x11\x03\x44\x84\x37\x94\x67"
        "\x7f\xd1\x70\x09\x5a\xf8\x76\x65\xd9\xb0\xfb\xe2\x55\xeb\x95";
    aes_key192_t key = "0123456789abcdefghijklmn";
    uint8_t *msg;
    size_t len_msg;
    char expected_msg[] = "Hello from my super AES library";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_192, key, AES_ECB);
    msg = aes_decrypt(&aes, enc, 32, &len_msg);
    cr_assert_not_null(msg);
    cr_expect_eq(len_msg, strlen(expected_msg));
    cr_assert_eq(memcmp(msg, expected_msg, len_msg), 0);
    free(msg);
}

Test(aes_decrypt, ecb_192_null_key)
{
    uint8_t enc[] =
        "\x7c\xd7\x2f\x3d\xff\x65\x29\xbc\x7e\xe5\x9a\x1c\x55\x6a\xb6\x21\xf6"
        "\x70\x70\xeb\xcd\x43\xce\x09\xd7\x4b\x75\x07\xe1\xfa\x17\x52";
    aes_key192_t key = { 0 };
    uint8_t *msg;
    size_t len_msg;
    char expected_msg[] = "Hello from my super AES library";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_192, key, AES_ECB);
    msg = aes_decrypt(&aes, enc, 32, &len_msg);
    cr_assert_not_null(msg);
    cr_expect_eq(len_msg, strlen(expected_msg));
    cr_assert_eq(memcmp(msg, expected_msg, len_msg), 0);
    free(msg);
}

Test(aes_decrypt, ecb_192_null_msg)
{
    uint8_t enc[] =
        "\x03\x66\x75\xac\x1b\x76\x53\x5b\xc7\x36\x38\x60\xc3\x66\x92\x69";
    aes_key192_t key = "0123456789abcdefghijklmn";
    uint8_t *msg;
    size_t len_msg;
    char expected_msg[] = "";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_192, key, AES_ECB);
    msg = aes_decrypt(&aes, enc, 16, &len_msg);
    cr_assert_not_null(msg);
    cr_expect_eq(len_msg, strlen(expected_msg));
    cr_assert_eq(memcmp(msg, expected_msg, len_msg), 0);
    free(msg);
}

Test(aes_decrypt, ecb_192_null_key_and_msg)
{
    uint8_t enc[] =
        "\x02\xbb\x29\x25\x27\xe7\x26\xfd\x51\xeb\x29\x89\x4d\x6f\x0a\xad";
    aes_key192_t key = { 0 };
    uint8_t *msg;
    size_t len_msg;
    char expected_msg[] = "";
    aes_ctx_t aes;

    aes_ctx_init(&aes, AES_192, key, AES_ECB);
    msg = aes_decrypt(&aes, enc, 16, &len_msg);
    cr_assert_not_null(msg);
    cr_expect_eq(len_msg, strlen(expected_msg));
    cr_assert_eq(memcmp(msg, expected_msg, len_msg), 0);
    free(msg);
}