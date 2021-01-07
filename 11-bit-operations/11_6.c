#include <stdio.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

int main(void) {
    unsigned int bit = 88;

    printf("%d ("BYTE_TO_BINARY_PATTERN") to "BYTE_TO_BINARY_PATTERN"\n", bit, BYTE_TO_BINARY(bit), BYTE_TO_BINARY(shifted_bits(bit)));
    return 0;
}

int shifted_bits(unsigned int bit) {
    int new_bit = 0;
    
    for (int i = 0x80; i > 0; i = (i >> 1)) {
        if (bit & i) {
            new_bit >>= 1;
            new_bit |= 0x80;
        }
    }

    return new_bit;
}