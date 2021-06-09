# AES-library

AES library in C

# Features

- [x] AES ECB
- [x] AES CBC
- [x] Encryption from 128 (useful) to 4096 (overkill) bytes
- [x] Almost no malloc

# Tests

```
------------------------------------------------------------------------------
                           GCC Code Coverage Report
Directory: .
------------------------------------------------------------------------------
File                                       Lines    Exec  Cover   Missing
------------------------------------------------------------------------------
src/aes.c                                     20      14    70%   16-21
src/aes_change.c                              13      13   100%   
src/aes_decrypt.c                             30      28    93%   35-36
src/aes_encrypt.c                             27      27   100%   
src/aes_key_expansion.c                       36      33    91%   20,22,30
src/aes_padding.c                             23      23   100%   
src/aes_random.c                              10      10   100%   
src/aes_tools.c                               14      14   100%   
src/matrix_functions/matrix_add_round_key.c    5       5   100%   
src/matrix_functions/matrix_mix_columns.c     19      19   100%   
src/matrix_functions/matrix_shift_rows.c      36      36   100%   
src/matrix_functions/matrix_sub_bytes.c       10      10   100%   
------------------------------------------------------------------------------
TOTAL                                        243     232    95%
-----------------------------------------------------------------------------
```