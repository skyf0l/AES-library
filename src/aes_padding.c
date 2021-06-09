/*
** EPITECH PROJECT, 2021
** AES_PADDING
** File description:
** Aes_padding function
*/

#include <stdlib.h>
#include <string.h>

#include "aes.h"

aes_block_t *aes_pad(const uint8_t *data, size_t len, size_t *nb_blocks)
{
    aes_block_t *blocks;
    size_t padding_len = AES_BLOCK_SIZE - len % AES_BLOCK_SIZE;

    *nb_blocks = len / AES_BLOCK_SIZE + 1;
    blocks = malloc(sizeof(aes_block_t) * *nb_blocks);
    if (!blocks)
        return NULL;
    memset(blocks[*nb_blocks - 1], padding_len, sizeof(aes_block_t));
    memcpy(blocks, data, len);
    return (aes_block_t *) blocks;
}

uint8_t *aes_unpad(const aes_block_t *blocks, size_t nb_blocks, size_t *len)
{
    uint8_t *data;
    size_t padding_len = blocks[nb_blocks - 1][AES_BLOCK_SIZE - 1];

    *len = nb_blocks * AES_BLOCK_SIZE - padding_len;
    if (padding_len == 0 || padding_len > AES_BLOCK_SIZE)
        return NULL;
    data = malloc(sizeof(char) * (*len + 1));
    if (!data)
        return NULL;
    memcpy(data, blocks, *len);
    data[*len] = 0;
    return data;
}

int aes_unpad_buffer(aes_block_t *blocks, size_t nb_blocks, size_t *len)
{
    size_t padding_len = blocks[nb_blocks - 1][AES_BLOCK_SIZE - 1];

    *len = nb_blocks * AES_BLOCK_SIZE - padding_len;
    if (padding_len == 0 || padding_len > AES_BLOCK_SIZE)
        return -1;
    ((uint8_t *) blocks)[*len] = 0;
    return EXIT_SUCCESS;
}