#include <stdio.h>

// Since there are no data type for 4-bit ints, we create it ourselves
struct split_int {
    unsigned int four_bit_value_1 : 4;
    unsigned int four_bit_value_2 : 4;
    unsigned int four_bit_value_3 : 4;
    unsigned int four_bit_value_4 : 4;
    unsigned int four_bit_value_5 : 4;
    unsigned int four_bit_value_6 : 4;
    unsigned int four_bit_value_7 : 4;
    unsigned int four_bit_value_8 : 4;
};

int main(void) {
    int bit_32_int = 458289420;
    struct split_int result;

    result.four_bit_value_1 = (bit_32_int & 0xF);
    result.four_bit_value_2 = (bit_32_int >> 4) & 0xF;
    result.four_bit_value_3 = (bit_32_int >> 8) & 0xF;
    result.four_bit_value_4 = (bit_32_int >> 12) & 0xF;
    result.four_bit_value_5 = (bit_32_int >> 16) & 0xF;
    result.four_bit_value_6 = (bit_32_int >> 20) & 0xF;
    result.four_bit_value_7 = (bit_32_int >> 24) & 0xF;
    result.four_bit_value_8 = (bit_32_int >> 28) & 0xF;

    return 0;
}