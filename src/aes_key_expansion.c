/*
** EPITECH PROJECT, 2021
** AES_KEY_EXPANSION
** File description:
** Aes_key_expansion function
*/

#include <string.h>

#include "aes.h"
#include "aes_boxes.h"

#include "aes_tools.h"

uint8_t gen_next_rcon(uint8_t rcon)
{
    return ((rcon << 1) ^ (0x11b & -(rcon >> 7))) & 0xff;
}

void rotate_key_block(aes_key_block_t key_block)
{
    uint8_t tmp = key_block[0];

    key_block[0] = key_block[1];
    key_block[1] = key_block[2];
    key_block[2] = key_block[3];
    key_block[3] = tmp;
}

void sbox_key_block(aes_key_block_t key_block)
{
    for (size_t k = 0; k < AES_KEY_BLOCK_SIZE; k++)
        key_block[k] = AES_SBOX[key_block[k]];
}

void gen_next_round_key(
    aes_matrix_t round_key, aes_matrix_t prev_round_key, uint8_t rcon)
{
    uint8_t byte;

    for (int k = 0; k < 4; k++) {
        byte = prev_round_key[0][k];
        byte ^= AES_SBOX[prev_round_key[3][(k + 1) % 4]];
        if (k == 0)
            byte ^= rcon;
        round_key[0][k] = byte;
    }
    for (int k = 1; k < 4; k++) {
        for (int i = 0; i < 4; i++) {
            byte = prev_round_key[k][i];
            byte ^= round_key[k - 1][i];
            round_key[k][i] = byte;
        }
    }
}

void aes_key_expansion(aes_expended_key_t round_keys, enum aes_key_len key_len,
    const aes_key_t key, size_t nb_rounds)
{
    uint8_t rcon = AES_INIT_RCON;
    aes_key_block_t *key_blocks = (aes_key_block_t *) round_keys;
    size_t nk = key_len / AES_KEY_BLOCK_SIZE;
    size_t key_block = nk;

    memcpy(key_blocks, key, key_len);
    for (; key_block < AES_KEY_BLOCK_SIZE * (nb_rounds + 1); key_block++) {
        memcpy(key_blocks[key_block], key_blocks[key_block - 1],
            AES_KEY_BLOCK_SIZE);
        if (key_block % nk == 0) {
            rotate_key_block(key_blocks[key_block]);
            sbox_key_block(key_blocks[key_block]);
            rcon = gen_next_rcon(rcon);
            key_blocks[key_block][0] ^= rcon;
        } else if (nk > 6 && key_block % nk == 4) {
            sbox_key_block(key_blocks[key_block]);
        }
        for (size_t k = 0; k < AES_KEY_BLOCK_SIZE; k++)
            key_blocks[key_block][k] ^= key_blocks[key_block - nk][k];
    }
}