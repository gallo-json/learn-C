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
    unsigned int bit = 27;

    printf("%d ("BYTE_TO_BINARY_PATTERN") has %d set bits\n", bit, BYTE_TO_BINARY(bit), count_bits(bit));
    return 0;
}

int count_bits(unsigned int bit) {
    int count = 0;
    // Loop 
    for (int i = 0x80; i > 0; i = (i >> 1)) {
        if (bit & i) ++count;
    }

    return count;
}