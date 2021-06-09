/*
** EPITECH PROJECT, 2021
** AES_RANDOM
** File description:
** Aes_random function
*/

#include <fcntl.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

#include "aes.h"

int aes_gen_n_random_bytes(uint8_t *buff, size_t buff_len)
{
    int fd = open("/dev/urandom", O_RDONLY);

    if (fd == -1)
        return -1;
    if (read(fd, buff, buff_len) != (ssize_t) buff_len)
        return -1;
    close(fd);
    return EXIT_SUCCESS;
}

int aes_gen_random_key(enum aes_key_len key_len, aes_key_t key)
{
    return aes_gen_n_random_bytes(key, key_len);
}

int aes_gen_random_iv(aes_iv_t iv)
{
    return aes_gen_n_random_bytes(iv, AES_BLOCK_SIZE);
}