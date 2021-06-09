/*
** EPITECH PROJECT, 2021
** TESTS_AES_ROUND_ENC_DEC
** File description:
** Test aes_round_enc_dec
*/

#include <criterion/criterion.h>

#include "tests_aes.h"

#include "aes.h"
#include "aes_tools.h"

Test(aes_round_encrypt_block, basic_null_block)
{
    aes_matrix_t round_key = { { 48, 49, 50, 51 }, { 52, 53, 54, 55 },
        { 56, 57, 97, 98 }, { 99, 100, 101, 102 } };
    aes_matrix_t block = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 },
        { 0, 0, 0, 0 } };
    aes_matrix_t expected_enc_block = { { 83, 82, 81, 80 }, { 87, 86, 85, 84 },
        { 91, 90, 2, 1 }, { 0, 7, 6, 5 } };

    aes_round_encrypt_block(block, round_key);
    CHECK_MATRIX_EQUALITY(block, expected_enc_block);
}

Test(aes_round_encrypt_block, basic_null_key)
{
    aes_matrix_t round_key = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 },
        { 0, 0, 0, 0 } };
    aes_matrix_t block = { { 48, 49, 50, 51 }, { 52, 53, 54, 55 },
        { 56, 57, 97, 98 }, { 99, 100, 101, 102 } };
    aes_matrix_t expected_enc_block = { { 117, 42, 2, 19 },
        { 136, 40, 206, 234 }, { 114, 126, 183, 70 }, { 16, 203, 211, 155 } };

    aes_round_encrypt_block(block, round_key);
    CHECK_MATRIX_EQUALITY(block, expected_enc_block);
}

Test(aes_round_encrypt_block, basic_null_block_two_rounds)
{
    aes_matrix_t round_key = { { 48, 49, 50, 51 }, { 52, 53, 54, 55 },
        { 56, 57, 97, 98 }, { 99, 100, 101, 102 } };
    aes_matrix_t block = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 },
        { 0, 0, 0, 0 } };
    aes_matrix_t expected_enc_block = { { 37, 87, 61, 15 },
        { 103, 235, 248, 173 }, { 239, 217, 68, 125 }, { 37, 100, 97, 199 } };

    aes_round_encrypt_block(block, round_key);
    aes_round_encrypt_block(block, round_key);
    CHECK_MATRIX_EQUALITY(block, expected_enc_block);
}

Test(aes_round_decrypt_block, basic_null_block)
{
    aes_matrix_t round_key = { { 48, 49, 50, 51 }, { 52, 53, 54, 55 },
        { 56, 57, 97, 98 }, { 99, 100, 101, 102 } };
    aes_matrix_t block = { { 83, 82, 81, 80 }, { 87, 86, 85, 84 },
        { 91, 90, 2, 1 }, { 0, 7, 6, 5 } };
    aes_matrix_t expected_enc_block = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 },
        { 0, 0, 0, 0 }, { 0, 0, 0, 0 } };

    aes_round_decrypt_block(block, round_key);
    CHECK_MATRIX_EQUALITY(block, expected_enc_block);
}

Test(aes_round_decrypt_block, basic_null_key)
{
    aes_matrix_t round_key = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 },
        { 0, 0, 0, 0 } };
    aes_matrix_t block = { { 117, 42, 2, 19 }, { 136, 40, 206, 234 },
        { 114, 126, 183, 70 }, { 16, 203, 211, 155 } };
    aes_matrix_t expected_enc_block = { { 48, 49, 50, 51 }, { 52, 53, 54, 55 },
        { 56, 57, 97, 98 }, { 99, 100, 101, 102 } };

    aes_round_decrypt_block(block, round_key);
    CHECK_MATRIX_EQUALITY(block, expected_enc_block);
}

Test(aes_round_decrypt_block, basic_null_block_two_rounds)
{
    aes_matrix_t round_key = { { 48, 49, 50, 51 }, { 52, 53, 54, 55 },
        { 56, 57, 97, 98 }, { 99, 100, 101, 102 } };
    aes_matrix_t block = { { 37, 87, 61, 15 }, { 103, 235, 248, 173 },
        { 239, 217, 68, 125 }, { 37, 100, 97, 199 } };
    aes_matrix_t expected_enc_block = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 },
        { 0, 0, 0, 0 }, { 0, 0, 0, 0 } };

    aes_round_decrypt_block(block, round_key);
    aes_round_decrypt_block(block, round_key);
    CHECK_MATRIX_EQUALITY(block, expected_enc_block);
}