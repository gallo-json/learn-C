#include <stdio.h>

#define SIZE 7

int arr[SIZE] = {1, 2, 3, 4, 5, 4, 2};

int main(void) {
    int num_to_find = 5;
    printf("%d appears %d time(s)\n", num_to_find, count(num_to_find, arr, SIZE));
    return (0);
}

// Function must be recursive, according to the excercise

int count(int number, int array[], int length) {
    if (length == 0) return (0);

    return (number == array[0]) + count(number, array + 1, length - 1);
}