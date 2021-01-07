#include <stdio.h>

#define X_SIZE 10
#define Y_SIZE 10

char graphics[X_SIZE / 8][Y_SIZE];

#define SET_BIT(x, y) graphics[x / 8][y] |= (0x80 >> (x % 8))

#define CLEAR_BIT(x, y) graphics[x / 8][y] &= ~(0x80 << (x % 8))

int main(void) {
    void print_graphics(void);

    for (int x = 0; x < X_SIZE; ++x) {
        for (int y = 0; y < Y_SIZE; ++y) {
            if (x != y) SET_BIT(x, y);
        }
    }

    print_graphics();

    return 0;
}

void print_graphics(void) {
    int x; int y; unsigned int bit;

    for (y = 0; y < Y_SIZE; ++ y) {
        for (x = 0; x < X_SIZE / 8; ++x) {
            for (bit = 0x80; bit > 0; bit = (bit >> 1)) {
                if ((graphics[x][y] & bit) != 0) printf("X");
                else printf(".");
            }
        }
        printf("\n");
    }
}