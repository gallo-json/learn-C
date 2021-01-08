#include <stdio.h>

// 10-1
#define IS_DIVISIBLE(x) ((x) % 10 == 0 ? 1 : 0)

// 10-4
#define SWAP(x, y) (x ^= y ^= x ^= y)

int main(void) {
    int num1 = 100;
    int num2 = 58;

    printf("%d is divisible by 10? %d\n%d is divisible by 10? %d\n", num1, IS_DIVISIBLE(num1), num2, IS_DIVISIBLE(num2));

    SWAP(num1, num2);
    printf("Swapped. Num1 is is now %d and num2 is now %d\n", num1, num2);
}