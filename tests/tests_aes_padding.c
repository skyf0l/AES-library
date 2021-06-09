/*
** EPITECH PROJECT, 2021
** TESTS_AES_PADDING
** File description:
** Test aes_padding
*/

#include <criterion/criterion.h>

#include "tests_aes.h"

#include "aes_tools.h"

Test(aes_pad, basic_1_block_1)
{
    const uint8_t data[] = "";
    size_t len = 0;
    size_t nb_blocks;
    aes_block_t *blocks = aes_pad(data, len, &nb_blocks);
    const aes_block_t expected_blocks[] = { { 0x10, 0x10, 0x10, 0x10, 0x10,
        0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10 } };

    cr_assert_not_null(blocks);
    cr_assert_eq(nb_blocks, 1);
    CHECK_BLOCKS_EQUALITY(blocks, expected_blocks, nb_blocks);
    free(blocks);
}

Test(aes_pad, basic_1_block_2)
{
    const uint8_t data[] = "0";
    size_t len = 1;
    size_t nb_blocks;
    aes_block_t *blocks = aes_pad(data, len, &nb_blocks);
    const aes_block_t expected_blocks[] = {
        { '0', 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
            0x0f, 0x0f, 0x0f, 0x0f },
    };

    cr_assert_not_null(blocks);
    cr_assert_eq(nb_blocks, 1);
    CHECK_BLOCKS_EQUALITY(blocks, expected_blocks, nb_blocks);
    free(blocks);
}

Test(aes_pad, basic_1_block_3)
{
    const uint8_t data[] = "01";
    size_t len = 2;
    size_t nb_blocks;
    aes_block_t *blocks = aes_pad(data, len, &nb_blocks);
    const aes_block_t expected_blocks[] = {
        { '0', '1', 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e,
            0x0e, 0x0e, 0x0e, 0x0e },
    };

    cr_assert_not_null(blocks);
    cr_assert_eq(nb_blocks, 1);
    CHECK_BLOCKS_EQUALITY(blocks, expected_blocks, nb_blocks);
    free(blocks);
}

Test(aes_pad, basic_1_block_4)
{
    const uint8_t data[] = "0123456789abcd";
    size_t len = 14;
    size_t nb_blocks;
    aes_block_t *blocks = aes_pad(data, len, &nb_blocks);
    const aes_block_t expected_blocks[] = {
        { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd',
            0x02, 0x02 },
    };

    cr_assert_not_null(blocks);
    cr_assert_eq(nb_blocks, 1);
    CHECK_BLOCKS_EQUALITY(blocks, expected_blocks, nb_blocks);
    free(blocks);
}

Test(aes_pad, basic_1_block_5)
{
    const uint8_t data[] = "0123456789abcde";
    size_t len = 15;
    size_t nb_blocks;
    aes_block_t *blocks = aes_pad(data, len, &nb_blocks);
    const aes_block_t expected_blocks[] = {
        { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd',
            'e', 0x01 },
    };

    cr_assert_not_null(blocks);
    cr_assert_eq(nb_blocks, 1);
    CHECK_BLOCKS_EQUALITY(blocks, expected_blocks, nb_blocks);
    free(blocks);
}

Test(aes_pad, basic_2_block_1)
{
    const uint8_t data[] = "0123456789abcdef";
    size_t len = 16;
    size_t nb_blocks;
    aes_block_t *blocks = aes_pad(data, len, &nb_blocks);
    const aes_block_t expected_blocks[] = {
        { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd',
            'e', 'f' },
        { 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
            0x10, 0x10, 0x10, 0x10, 0x10 },
    };

    cr_assert_not_null(blocks);
    cr_assert_eq(nb_blocks, 2);
    CHECK_BLOCKS_EQUALITY(blocks, expected_blocks, nb_blocks);
    free(blocks);
}

Test(aes_pad, basic_2_block_2)
{
    const uint8_t data[] = "0123456789abcdef0";
    size_t len = 17;
    size_t nb_blocks;
    aes_block_t *blocks = aes_pad(data, len, &nb_blocks);
    const aes_block_t expected_blocks[] = {
        { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd',
            'e', 'f' },
        { '0', 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
            0x0f, 0x0f, 0x0f, 0x0f },
    };

    cr_assert_not_null(blocks);
    cr_assert_eq(nb_blocks, 2);
    CHECK_BLOCKS_EQUALITY(blocks, expected_blocks, nb_blocks);
    free(blocks);
}

Test(aes_pad, basic_2_block_3)
{
    const uint8_t data[] = "0123456789abcdef01";
    size_t len = 18;
    size_t nb_blocks;
    aes_block_t *blocks = aes_pad(data, len, &nb_blocks);
    const aes_block_t expected_blocks[] = {
        { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd',
            'e', 'f' },
        { '0', '1', 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e,
            0x0e, 0x0e, 0x0e, 0x0e },
    };

    cr_assert_not_null(blocks);
    cr_assert_eq(nb_blocks, 2);
    CHECK_BLOCKS_EQUALITY(blocks, expected_blocks, nb_blocks);
    free(blocks);
}

Test(aes_unpad, basic_1_block_1)
{
    const aes_block_t blocks[] = { { 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
        0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10 } };
    size_t nb_blocks = 1;
    size_t len;
    const uint8_t expected_data[] = "";
    uint8_t *data = aes_unpad(blocks, nb_blocks, &len);

    cr_assert_not_null(data);
    cr_assert_eq(len, 0);
    cr_assert_eq(memcmp(data, expected_data, len), 0);
    free(data);
}

Test(aes_unpad, basic_1_block_2)
{
    const aes_block_t blocks[] = { { '0', 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f } };
    size_t nb_blocks = 1;
    size_t len;
    const uint8_t expected_data[] = "0";
    uint8_t *data = aes_unpad(blocks, nb_blocks, &len);

    cr_assert_not_null(data);
    cr_assert_eq(len, 1);
    cr_assert_eq(memcmp(data, expected_data, len), 0);
    free(data);
}

Test(aes_unpad, basic_1_block_3)
{
    const aes_block_t blocks[] = { { '0', '1', 0x0e, 0x0e, 0x0e, 0x0e, 0x0e,
        0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e } };
    size_t nb_blocks = 1;
    size_t len;
    const uint8_t expected_data[] = "01";
    uint8_t *data = aes_unpad(blocks, nb_blocks, &len);

    cr_assert_not_null(data);
    cr_assert_eq(len, 2);
    cr_assert_eq(memcmp(data, expected_data, len), 0);
    free(data);
}

Test(aes_unpad, basic_1_block_4)
{
    const aes_block_t blocks[] = { { '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'a', 'b', 'c', 'd', 0x02, 0x02 } };
    size_t nb_blocks = 1;
    size_t len;
    const uint8_t expected_data[] = "0123456789abcd";
    uint8_t *data = aes_unpad(blocks, nb_blocks, &len);

    cr_assert_not_null(data);
    cr_assert_eq(len, 14);
    cr_assert_eq(memcmp(data, expected_data, len), 0);
    free(data);
}

Test(aes_unpad, basic_1_block_5)
{
    const aes_block_t blocks[] = { { '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'a', 'b', 'c', 'd', 'e', 0x01 } };
    size_t nb_blocks = 1;
    size_t len;
    const uint8_t expected_data[] = "0123456789abcde";
    uint8_t *data = aes_unpad(blocks, nb_blocks, &len);

    cr_assert_not_null(data);
    cr_assert_eq(len, 15);
    cr_assert_eq(memcmp(data, expected_data, len), 0);
    free(data);
}

Test(aes_unpad, basic_2_block_1)
{
    const aes_block_t blocks[] = {
        { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd',
            'e', 'f' },
        { 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
            0x10, 0x10, 0x10, 0x10, 0x10 },
    };
    size_t nb_blocks = 2;
    size_t len;
    const uint8_t expected_data[] = "0123456789abcdef";
    uint8_t *data = aes_unpad(blocks, nb_blocks, &len);

    cr_assert_not_null(data);
    cr_assert_eq(len, 16);
    cr_assert_eq(memcmp(data, expected_data, len), 0);
    free(data);
}

Test(aes_unpad, basic_2_block_2)
{
    const aes_block_t blocks[] = {
        { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd',
            'e', 'f' },
        { '0', 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
            0x0f, 0x0f, 0x0f, 0x0f },
    };
    size_t nb_blocks = 2;
    size_t len;
    const uint8_t expected_data[] = "0123456789abcdef0";
    uint8_t *data = aes_unpad(blocks, nb_blocks, &len);

    cr_assert_not_null(data);
    cr_assert_eq(len, 17);
    cr_assert_eq(memcmp(data, expected_data, len), 0);
    free(data);
}

Test(aes_unpad, basic_2_block_3)
{
    const aes_block_t blocks[] = {
        { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd',
            'e', 'f' },
        { '0', '1', 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e,
            0x0e, 0x0e, 0x0e, 0x0e },
    };
    size_t nb_blocks = 2;
    size_t len;
    const uint8_t expected_data[] = "0123456789abcdef01";
    uint8_t *data = aes_unpad(blocks, nb_blocks, &len);

    cr_assert_not_null(data);
    cr_assert_eq(len, 18);
    cr_assert_eq(memcmp(data, expected_data, len), 0);
    free(data);
}