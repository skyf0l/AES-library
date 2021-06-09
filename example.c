/*
** EPITECH PROJECT, 2021
** EXAMPLE
** File description:
** Example
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aes.h"

void print_bytes(const uint8_t *bytes, size_t size)
{
    for (size_t k = 0; k < size; k++)
        printf("%02x", bytes[k]);
    printf("\n");
}

int main(void)
{
    char msg[] = "Hello from my super AES library!";

    aes_key128_t key = "0123456789abcdef";
    aes_iv_t iv = "abcdefghijklmnop";
    aes_ctx_t aes;
    // aes_ctx_init(&aes, AES_128, key, AES_ECB);
    aes_ctx_init_cbc_iv(&aes, AES_128, key, iv);

    size_t len_cipher;
    uint8_t *cipher = aes_encrypt(&aes, (uint8_t *) msg, strlen(msg), &len_cipher);
    printf("Ciphertext (hex): ");
    print_bytes(cipher, len_cipher);

    size_t len_plain;
    uint8_t *plain = aes_decrypt(&aes, cipher, len_cipher, &len_plain);
    printf("Plaintext: %s\n", plain);
    free(cipher);
    free(plain);
    return EXIT_SUCCESS;
}